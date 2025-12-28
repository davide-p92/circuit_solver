#pragma once

#include <QMainWindow>
#include <QTextEdit>
#include <QPushButton>
#include "algorithms.hpp"

class MainWindow : public QMainWindow {
	Q_OBJECT

public:
	MainWindow(QWidget *parent = nullptr);
	~MainWindow();

private slots:
	void onSimulate();

private:
	QTextEdit *outputBox;
	QPushButton *simulateButton;
	Circuit circuit;
};
