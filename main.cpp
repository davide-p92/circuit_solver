#include "algorithms.hpp"

int main() {
    // Create a circuit

    Circuit circuit;
    double frequency;
    int nNodes;

    std::cout << "Oh Weise, verrate die Frequenz in Hz (0 für Gleichstrom):\n";
    std::cin >> frequency;
    double omega = 2 * M_PI * frequency;
    circuit.setOmega(omega);

    std::cout << "Wie viele Knoten hat dein Zauberkreis?\n";
    std::cin >> nNodes;

    std::cout << "Nun lasst uns die Zweige beschreiben (ende mit -1 -1):\n";

    std::vector<Bipole*> bipoles;
    int branchCount = 0;
    
    while (true) {
	int node1, node2;
	std::cout << "Zweig " << ++branchCount << " - Von Knoten und zu Knoten: ";
	std::cin >> node1 >> node2;

	if (node1 == -1 || node2 == -1) break;
	if (node1 < 0 || node1 >= nNodes || node2 < 0 || node2 >= nNodes) {
	    std::cout << "Ungültige Knoten. Versuche es erneut.\n";
	    branchCount--;
	    continue;
	}

	char type;
	std::cout << "Welcher Type ist dieser Zweig? (V, R, C, L, I):\n";
	std::cin >> type;
	if (type != 'V' && type != 'I' && type != 'C' && type != 'L' && type != 'R') {
 	    std::cout << "Ungültiger Type. Versuche es erneut.\n";
	    continue;
	}
	
	double value;
	std::cout << "Welchen Wert hat er?\n";
	std::cin >> value;

	Bipole* bipole = nullptr;
	switch (type) {
		case 'V':
		case 'v':
		    bipole = new VoltageSource(value, node1, node2);
		    break;
		case 'R':
		case 'r':
		    bipole = new Resistor(value, node1, node2);
		    break;
		case 'C':
		case 'c':
		    bipole = new Capacitor(value, node1, node2);
		    break;
		case 'L':
		case 'l':
		    bipole = new Inductor(value, node1, node2);
		    break;
		case 'I':
		case 'i':
		    bipole = new CurrentSource(value, node1, node2);
		    break;
		default:
		    std::cout << "Unbekannter Typ! Zweig wird übersprungen!\n";
		    branchCount--;
		    continue;
	}

	if (bipole) {
	    bipoles.push_back(bipole);
	    circuit.addBipole(bipole);
	}
    }

    // Solve
    circuit.KCLSolve();
    circuit.printResults();

    // Clean up
    for (auto bipole : bipoles) {
	delete bipole;
    }

    return 0;
}

