#include <iostream>
#include <complex>
#include <vector>
#include <eigen-3.4.0/Eigen/Dense>


enum Type {
    RESISTOR,
    CAPACITOR,
    INDUCTOR,
    VOLTAGE_SOURCE,
    CURRENT_SOURCE,
    GROUND,
    DIODE,
    TRANSISTOR
};

//bipole class
class Bipole {
public:
    int id;
    Type type;
    Bipole(int id, Type type, int node1, int node2) : id(id), type(type), node1(node1), node2(node2) {}
    //virtual void solve() {}
    virtual ~Bipole() {}
    virtual std::complex<double> getImpedance() const;
    std::complex<double> getVoltage() const {
        return voltage;
    }
    void setVoltage(std::complex<double> voltage) {
        this->voltage = voltage;
    }
    std::complex<double> getCurrent() const {
        return current;
    }
    void setCurrent(std::complex<double> current) {
        this->current = current;
    }
    int getNode1() const {
        return node1;
    }
    int getNode2() const {
        return node2;
    }
    Type getType() const {
        return type;
    }
    bool getIsActive() const {
        return isActive;
    }
    virtual void updateCurrent() {
        if (abs(impedance) != 0)
        current = voltage / impedance;
    }
    void setOmega(double omega) { this->omega = omega; }
private:
    int node1;
    int node2;
    std::complex<double> voltage;
    std::complex<double> current;
    std::complex<double> impedance;
    double omega = 0; //Assume at the start a continuous frequency / pulsation
    std::complex<double> power;
    bool isActive;
};


class Resistor : public Bipole {
public:
    Resistor(double resistance, int node1, int node2) : Bipole(0, Type::RESISTOR, node1, node2) {
        this->setResistance(resistance);
    };
    double getResistance() const;
    void setResistance(double resistance);
    std::complex<double> getPower() const;
    void setPower(std::complex<double> power);
    void print() const;
private:
    double resistance;
    std::complex<double> voltage;
    std::complex<double> current;
    std::complex<double> power;
    Type type = RESISTOR;
    bool isActive = false;
};

class Capacitor : public Bipole {
public:
    Capacitor(double capacitance, int node1, int node2) : Bipole(0, Type::CAPACITOR, node1, node2) {
        this->setCapacitance(capacitance);
    }
    double getCapacitance() const;
    void setCapacitance(double capacitance);
    std::complex<double> getPower() const;
    void setPower(std::complex<double> power);
    void print() const;
private:
    double capacitance;
    std::complex<double> voltage;
    std::complex<double> current;
    std::complex<double> power;
    Type type = CAPACITOR;
    bool isActive = false;
};

class Inductor : public Bipole {
public:
    Inductor(double inductance, int node1, int node2) : Bipole(0, Type::INDUCTOR, node1, node2) {
        this->setInductance(inductance);
    }
    double getInductance() const;
    void setInductance(double inductance);
    std::complex<double> getPower() const;
    void setPower(std::complex<double> power);
    void print() const;
private:
    double inductance;
    std::complex<double> voltage;
    std::complex<double> current;
    std::complex<double> power;
    Type type = INDUCTOR;
    bool isActive = false;
};

class VoltageSource : public Bipole {
public:
    VoltageSource(std::complex<double> voltage, int node1, int node2) : Bipole(0, Type::VOLTAGE_SOURCE, node1, node2) {
        this->setVoltage(voltage);
    };
    VoltageSource(double voltage, int node1, int node2);
    std::complex<double> getPower() const;
    void setPower(std::complex<double> power);
    void print() const;
    /*For KCL the voltage sources do not account for current vector but 
    will be part of the solutions*/
    void updateCurrent() override {
        setCurrent(0);
    }
private:
    std::complex<double> power;
    Type type = VOLTAGE_SOURCE;
    bool isActive = false;
};

class CurrentSource : public Bipole {
public:
    CurrentSource(std::complex<double> current, int node1, int node2) : Bipole(id, Type::CURRENT_SOURCE, node1, node2) {
        this->setCurrent(current);
    };
    CurrentSource(double current, int node1, int node2);
    std::complex<double> getPower() const;
    void setPower(double power);
    void print() const;
private:
    std::complex<double> power;
    Type type = CURRENT_SOURCE;
    bool isActive = false;
};

class Diode : public Bipole {
public:
    Diode(int id, double voltageF, int node1, int node2) : Bipole(id, Type::DIODE, node1, node2) {
        this->setVoltage(voltageF);
    };
    double getPower() const;
    void setPower(double power);
    void print() const;
};

class Ground : public Bipole {
public:
    Ground() : Bipole(0, Type::GROUND, 0, 0) {
        this->setVoltage(0.0);
        this->setCurrent(0.0);
    };
    double getPower() const;
    void setPower(double power);
    void print() const;
};
