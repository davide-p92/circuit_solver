#include "algorithms.hpp"


void Circuit::addBipole(Bipole* bipole) {
    bipoles.push_back(bipole);
}

void Circuit::setActiveComponents() {
    for (Bipole* bipole : bipoles) {
        if (bipole->getIsActive()) {
            hasActiveComponents = true;
            return;
        }
    }
    hasActiveComponents = false;
}

std::vector<Bipole*> Circuit::getBipoles(int node) const {
    std::vector<Bipole*> bipoles_node;
    for (Bipole* bipole : bipoles) {
        if (bipole->getNode1() == node || bipole->getNode2() == node) {
            bipoles_node.push_back(bipole);
        }
    }
    return bipoles_node;
}

Eigen::MatrixXd Circuit::getA() const {
    // Determine the number of nodes by finding the maximum node index
    int maxNode = -1;
    for (const Bipole* bipole : bipoles) {
        maxNode = std::max(maxNode, bipole->getNode1());
        maxNode = std::max(maxNode, bipole->getNode2());
    }
    int n = maxNode + 1; // Number of nodes

    Eigen::MatrixXd A(n, n);
    A.setZero();
    for (const Bipole* bipole : bipoles) {
        if (bipole->getType() == Type::RESISTOR) {
            const Resistor* resistor = dynamic_cast<const Resistor*>(bipole);
            if (resistor) {
                int node1 = bipole->getNode1();
                int node2 = bipole->getNode2();
                double conductance = 1.0 / resistor->getResistance();
                if (node1 >= 0 && node2 >= 0) {

                    A(node1, node2) = conductance;
                    A(node2, node1) = conductance; // Assuming undirected graph
                }
            }
        } else if (bipole->getType() == Type::CAPACITOR || bipole->getType() == Type::INDUCTOR) {
            int node1 = bipole->getNode1();
            int node2 = bipole->getNode2();
            std::complex<double> impedance = bipole->getImpedance();
            if (node1 >= 0 && node2 >= 0) {
                A(node1, node2) = 1 / impedance.imag();
                A(node2, node1) = 1 / impedance.imag(); // Assuming undirected graph
            }
        }
    }
    return A;
}

Eigen::MatrixXd Circuit::getM() const {
    // Determine the number of nodes and edges
    int maxNode = -1;
    int numEdges = bipoles.size();
    for (const Bipole* bipole : bipoles) {
        maxNode = std::max(maxNode, bipole->getNode1());
        maxNode = std::max(maxNode, bipole->getNode2());
    }
    int n = maxNode + 1; // Number of nodes

    Eigen::MatrixXd B(n, numEdges);
    B.setZero();
    for (int i = 0; i < numEdges; ++i) {
        const Bipole* bipole = bipoles[i];
        int node1 = bipole->getNode1();
        int node2 = bipole->getNode2();
        if (node1 >= 0) B(node1, i) = 1;
        if (node2 >= 0) B(node2, i) = -1;
    }
    return B;
}

//Matrix to consider voltage sources used in KCL
Eigen::MatrixXd Circuit::getC() const {
    // Determine the number of nodes and edges
    int maxNode = -1;
    int numEdges = bipoles.size();
    for (const Bipole* bipole : bipoles) {
        maxNode = std::max(maxNode, bipole->getNode1());
        maxNode = std::max(maxNode, bipole->getNode2());
    }
    int n = maxNode + 1; // Number of nodes

    Eigen::MatrixXd C(n, numEdges);
    C.setZero();
    for (int i = 0; i < numEdges; ++i) {
        const Bipole* bipole = bipoles[i];
        if (bipole->getType() == Type::VOLTAGE_SOURCE) {
            int node1 = bipole->getNode1();
            int node2 = bipole->getNode2();
            if (node1 >= 0) C(node1, i) = 1;
            if (node2 >= 0) C(node2, i) = -1;
        }
    }
    return C;
}

//Solution using KCL
void Circuit::KCLSolve() {
    // Determine number of nodes and voltage sources
    int maxNode = -1;
    int numVoltageSources = 0;

    for (Bipole* bipole : bipoles) {
	maxNode = std::max(maxNode, bipole->getNode1());
	maxNode = std::max(maxNode, bipole->getNode2());
	if (bipole->getType() == Type::VOLTAGE_SOURCE) {
	    numVoltageSources++;
	}
    }
    int n = maxNode + 1; // Number of nodes
    int refNode = 0;

    int numEdges = bipoles.size();

    // Build admittance matrix Y (numEdges x numEdges)
    Eigen::MatrixXcd Y = Eigen::MatrixXcd::Zero(numEdges, numEdges);
    Eigen::VectorXcd Vb = Eigen::VectorXcd::Zero(numEdges);
    int vsIndex = 0;
    Eigen::VectorXcd I_branch = Eigen::VectorXcd::Zero(numEdges);
    for (int i = 0; i < numEdges; ++i) {
	Bipole* bipole = bipoles[i];
	if (bipole->getType() == Type::VOLTAGE_SOURCE) {
	    Y(i, i) = std::complex<double>(0.0, 0.0); // Ideal Voltage Source
	    Vb(i) = bipole->getVoltage();
	    ++vsIndex;
	} else {
	    if (bipole->getType() == Type::RESISTOR || bipole->getType() == Type::CAPACITOR || bipole->getType() == Type::INDUCTOR) {
	        Y(i, i) = 1.0 / bipole->getImpedance();
	    } else if (bipole->getType() == Type::CURRENT_SOURCE) {
		I_branch(i) = bipole->getCurrent();
	    }
	}
	    // Skip setting Y for voltage sources
	 //   continue;
    }

    // --- 2) M (n x m) und C (n x k) ---
    Eigen::MatrixXcd M = Eigen::MatrixXcd::Zero(n, numEdges);
    Eigen::MatrixXcd C = Eigen::MatrixXcd::Zero(n, numVoltageSources);
    int vsIdx = 0;

    for (int j = 0; j < numEdges; ++j) {
	Bipole* bipole = bipoles[j];
	int node1 = bipole->getNode1();
	int node2 = bipole->getNode2();
	if (node1 != refNode) M(node1, j) = 1;
	if (node2 != refNode) M(node2, j) = -1;
	if (bipole->getType() == Type::VOLTAGE_SOURCE) {
	    if (node1 != refNode) C(node1, vsIdx) = 1;
	    if (node2 != refNode) C(node2, vsIdx) = -1;
	    ++vsIdx;
	}
    }

    // --- 3) Remove the reference rows explicitly   
    Eigen::MatrixXcd M_reduced(n-1, numEdges);
    Eigen::MatrixXcd C_reduced(n-1, numVoltageSources);
    for (int r = 0, rr = 0; r < n; ++r) {
	if (r == refNode) continue;
	M_reduced.row(rr) = M.row(r);
	C_reduced.row(rr) = C.row(r);
	++rr;
    }

    // --- 4) Build the augmented system
    Eigen::MatrixXcd G = M_reduced * Y * M_reduced.adjoint();
    int augSize = (n - 1) + numVoltageSources;
    Eigen::MatrixXcd A_aug = Eigen::MatrixXcd::Zero(augSize, augSize);
    A_aug.topLeftCorner(n-1, n-1) = G;
    A_aug.topRightCorner(n-1, numVoltageSources) = C_reduced;
    A_aug.bottomLeftCorner(numVoltageSources, n-1) = C_reduced.adjoint();

    // --- 5) RHS: oben = - M_reduced * (Y*Vb + I_branch), unten = V_S
    Eigen::VectorXcd b_aug = Eigen::VectorXcd::Zero(augSize);
    Eigen::VectorXcd rhs_top = - M_reduced * (Y * Vb + I_branch);
    b_aug.head(n-1) = rhs_top;

    // Build V_S in same vs column order as C_reduced
    Eigen::VectorXcd V_S = Eigen::VectorXcd::Zero(numVoltageSources);
    vsIdx = 0;
    for (int j = 0; j < numEdges; ++j) {
	if (bipoles[j]->getType() == Type::VOLTAGE_SOURCE) {
	    V_S(vsIdx++) = bipoles[j]->getVoltage();
	}
    }
    b_aug.tail(numVoltageSources) = V_S;

    // --- 6) Solve the system
    Eigen::VectorXcd x_aug = A_aug.colPivHouseholderQr().solve(b_aug);

    // --- 7) Extract node voltages (excluding reference node)
    Eigen::VectorXcd nodeVoltages = Eigen::VectorXcd::Zero(n);
    for (int r = 0, rr = 0; r < n; ++r) {
	if (r == refNode) {
 	    nodeVoltages(r) = std::complex<double>(0.0, 0.0);
	    continue;
	}
	nodeVoltages(r) = x_aug(rr++);
    }

    // --- 8) Update bipole voltages and currents
    Eigen::VectorXcd branchVoltages = M.transpose() * nodeVoltages + Vb; // m-vector
    Eigen::VectorXcd branchCurrents = Y * branchVoltages + I_branch; // m-ve
    
    // Set standard Branch sizes
    for (int j = 0, vsj = 0; j < numEdges; ++j) {
	Bipole* bipole = bipoles[j];
	if (bipoles[j]->getType() == Type::VOLTAGE_SOURCE) {
	    // Current through Voltage source comes from x_aug
	    std::complex<double> i_v = x_aug.segment(n-1, numVoltageSources)(vsj++);
	    bipoles[j]->setCurrent(i_v);
	} else {
	    bipoles[j]->setCurrent(branchCurrents(j));
	}
    }
}

void Circuit::setOmega(double omega) {
    for (Bipole* bipole : bipoles) {
	bipole->setOmega(omega);
    }
}

void Circuit::printResults() const {
    for (const auto& bipole : bipoles) {
        std::cout << "Bipole between nodes " << bipole->getNode1() << " and " << bipole->getNode2()
                    << ": Voltage = " << bipole->getVoltage() << " V, Current = " << bipole->getCurrent()
                    << " A\n";
    }
}
