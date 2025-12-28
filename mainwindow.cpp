#include "mainwindow.h"
#include <QVBoxLayout>
#include <QWidget>
#include <sstream>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {

	// --- UI Grundlayout ---
	QWidget *central = new QWidget(this);
	QVBoxLayout *layout = new QVBoxLayout(central);

	simulateButton = new QPushButton("Simulieren", this);
	outputBox = new QTextEdit(this);
	outputBox->setReadOnly(true);

	layout->addWidget(simulateButton);
	layout->addWidget(outputBox);

	setCentralWidget(central);

	// --- Beispielschaltung bauen ---
	// Einfacher Kreis: Spannungsquelle 5V an Widerstand 100 Ohm
	circuit.addBipole(new VoltageSource(5.0, 0, 1));
	circuit.addBipole(new Resistor(100.0, 1, 0));

	// Event-Handler
	connect(simulateButton, &QPushButton::clicked, this, &MainWindow::onSimulate);
}

MainWindow::~MainWindow() {}

void MainWindow::onSimulate() {
	std::ostringstream oss;

	circuit.KCLSolve();
	for (auto b : circuit.getBipoles(0)) {
		oss << "Zwischen Node"
	 	    << b->getNode1() << " und " << b->getNode2()
		    << ": V=" << b->getVoltage() << " I=" << b->getCurrent() << "\n";
	}
	outputBox->setPlainText(QString::fromStdString(oss.str()));
}
