#include "bipoles.hpp"


VoltageSource::VoltageSource(double voltage, int node1, int node2)
	: VoltageSource(std::complex<double>(voltage, 0), node1, node2) {}

CurrentSource::CurrentSource(double current, int node1, int node2)
	: Bipole(0, Type::CURRENT_SOURCE, node1, node2) {
	    this->setCurrent(std::complex<double>(current, 0));
	}

std::complex<double> Bipole::getImpedance() const {
    if(type == Type::CAPACITOR) {
        const Capacitor* capacitor = dynamic_cast<const Capacitor*>(this);
        if (capacitor) {
  	    std::complex<double> imp;
	    if (omega != 0) {
            	imp = std::complex<double>(0, -1 / (capacitor->getCapacitance() * omega));
		return imp;
	    } else {
		return std::complex<double>(1e12, 0);
	    }
        }
    } else if(type == Type::INDUCTOR) {
        const Inductor* inductor = dynamic_cast<const Inductor*>(this);
        if (inductor) {
	    std::complex<double> imp;
	    if (omega != 0) {
            	imp = std::complex<double>(0, inductor->getInductance() * omega);
		return imp;
	    } else {
		return std::complex<double>(0, 0); //Kurzschluss
	    }
        }
    } else if(type == Type::RESISTOR) {
        const Resistor* resistor = dynamic_cast<const Resistor*>(this);
        return std::complex<double>(resistor->getResistance(), 0);
    } else {
        return std::complex<double>(0, 0);
    }
}

double Resistor::getResistance() const {
    return resistance;
}

void Resistor::setResistance(double resistance) {
    this->resistance = resistance;
}

void Resistor::print() const {
    std::cout << "Resistor: R = " << resistance << " Ohm, V = " << voltage << " V, I = " << current << " A, P = " << power << " W" << std::endl;
}

double Capacitor::getCapacitance() const {
    return capacitance;
}

void Capacitor::setCapacitance(double capacitance) {
    this->capacitance = capacitance;
}

void Capacitor::setPower(std::complex<double> power) {
    this->power = power;
}

void Capacitor::print() const {
    std::cout << "Capacitor: C = " << capacitance << " F, V = " << voltage << " V, I = " << current << " A, P = " << power << " W" << std::endl;
}

double Inductor::getInductance() const {
    return inductance;
}

void Inductor::setInductance(double inductance) {
    this->inductance = inductance;
}

std::complex<double> Inductor::getPower() const {
    return power;
}

void Inductor::setPower(std::complex<double> power) {
    this->power = power;
}

void Inductor::print() const {
    std::cout << "Inductor: L = " << inductance << " H, V = " << voltage << " V, I = " << current << " A, P = " << power << " W" << std::endl;
}
std::complex<double> VoltageSource::getPower() const {
    return power;
}

void VoltageSource::setPower(std::complex<double> power) {
    this->power = power;
}

void VoltageSource::print() const {
    std::cout << "Voltage Source: V = " << getVoltage().real() << " V, I = " << getCurrent().real() << " A, P = " << getPower().real() << " W" << std::endl;
}

std::complex<double> CurrentSource::getPower() const {
    return power;
}

void CurrentSource::setPower(double power) {
    this->power = power;
}

void CurrentSource::print() const {
    std::cout << "Current Source: I = " << getCurrent() << " A, V = " ;//<< voltage << " V, P = " << power << " W" << std::endl;
}
