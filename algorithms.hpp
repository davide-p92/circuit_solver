#include "bipoles.hpp"


//algorithm to represent a circuit
class Circuit {
public:
    Circuit() {}
    void addBipole(Bipole* bipole);
    //void connect(int i, int j);
    std::vector<Bipole*> getBipoles(int node) const;
    Eigen::MatrixXd getA() const;
    Eigen::MatrixXd getM() const;
    Eigen::MatrixXd getC() const;
    void setActiveComponents();
    void KCLSolve();
    void printResults() const;
    void setOmega(double omega);
private:
    double omega_ = 0;
    std::vector<Bipole*> bipoles;
    /*Adjacency matrix A with connections between nodes*/
    Eigen::MatrixXd A;
    Eigen::VectorXd b;
    Eigen::VectorXd x;
    /*Incidence matrix M with connections between nodes and edges*/
    Eigen::MatrixXd M;
    bool hasActiveComponents = false;
};
