#include "cuteulator.h"
#include "ui_cuteulator.h"

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
