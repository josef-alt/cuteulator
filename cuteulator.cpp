#include "cuteulator.h"
#include "ui_cuteulator.h"
#include <string>
#include <vector>

Cuteulator::Cuteulator(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Cuteulator)
{
    ui->setupUi(this);
}

Cuteulator::~Cuteulator()
{
    delete ui;
}

std::vector<std::string> expression;
std::string term = "";

// write expression to screen
void Cuteulator::update()
{
    QString exp;
    for(auto t : expression) {
        exp += QString::fromStdString(t);
    }
    exp += QString::fromStdString(term);

    ui->txtDisplay->setText(exp);
}

// button listeners
void Cuteulator::on_btn0_clicked()
{
    term += "0";
    update();
}

void Cuteulator::on_btn1_clicked()
{
    term += "1";
    update();
}

void Cuteulator::on_btn2_clicked()
{
    term += "2";
    update();
}

void Cuteulator::on_btn3_clicked()
{
    term += "3";
    update();
}

void Cuteulator::on_btn4_clicked()
{
    term += "4";
    update();
}

void Cuteulator::on_btn5_clicked()
{
    term += "5";
    update();
}

void Cuteulator::on_btn6_clicked()
{
    term += "6";
    update();
}

void Cuteulator::on_btn7_clicked()
{
    term += "7";
    update();
}

void Cuteulator::on_btn8_clicked()
{
    term += "8";
    update();
}

void Cuteulator::on_btn9_clicked()
{
    term += "9";
    update();
}
