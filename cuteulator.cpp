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

// determine whether terms are operators or operands
bool is_operator(std::string str)
{
    if("+" == str)  return true;
    if("-" == str)  return true;
    if("/" == str)  return true;
    if("*" == str)  return true;
    return false;
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

void Cuteulator::on_btnDecimal_clicked()
{
    // if the term is empty we need to determine whether to start a new term or append to a previous one
    if(term.empty())
    {
        std::string prev = expression.back();
        if(is_operator(prev))
        {
            term += ".";
            update();
            return;
        }
        else
        {
            term = prev;
            expression.pop_back();
        }
    }

    // if we are appending to an existing term there cannot be another decimal
    bool has_decimal = false;
    for(char c : term)
    {
        if(c == '.')
        {
            has_decimal = true;
        }
    }
    if(!has_decimal)
    {
        term += ".";
    }

    update();
}

void Cuteulator::on_btnMultiply_clicked()
{
    // push and clear for next term
    if(!term.empty())
    {
        expression.push_back(term);
        term.clear();
    }

    // can't start with m/d
    if(expression.empty())
    {
        return;
    }

    // can't do operations back to back
    if(!expression.empty())
    {
        if(is_operator(expression.back()))
        {
            expression.pop_back();
        }
    }

    expression.push_back("*");
    update();
}

void Cuteulator::on_btnDivide_clicked()
{
    // push and clear for next term
    if(!term.empty())
    {
        expression.push_back(term);
        term.clear();
    }

    // can't start with m/d
    if(expression.empty())
    {
        return;
    }

    // can't do operations back to back
    if(!expression.empty())
    {
        if(is_operator(expression.back()))
        {
            expression.pop_back();
        }
    }

    expression.push_back("/");
    update();
}

void Cuteulator::on_btnAdd_clicked()
{
    // push and clear for next term
    if(!term.empty())
    {
        expression.push_back(term);
        term.clear();
    }

    // can't start with m/d
    if(expression.empty())
    {
        return;
    }

    // can't do operations back to back
    if(!expression.empty())
    {
        if(is_operator(expression.back()))
        {
            expression.pop_back();
        }
    }

    expression.push_back("+");
    update();
}

void Cuteulator::on_btnSubtract_clicked()
{
    // push and clear for next term
    if(!term.empty())
    {
        expression.push_back(term);
        term.clear();
    }

    // can't start with m/d
    // TODO allow subtracting negatives
    if(expression.empty())
    {
        return;
    }

    // can't do operations back to back
    if(!expression.empty())
    {
        if(is_operator(expression.back()))
        {
            expression.pop_back();
        }
    }

    expression.push_back("-");
    update();
}

// delete one digit/operator
void Cuteulator::on_btnDelete_clicked()
{
    if(term.empty())
    {
        if(!expression.empty())
        {
            std::string prev = expression.back();
            expression.pop_back();

            // only delete the last character of the term
            prev.pop_back();
            term = prev;
        }
    }
    else
    {
        if(!term.empty())
        {
            term.pop_back();
        }
    }

    update();
}

// full clear
void Cuteulator::on_btnClear_clicked()
{
    expression.clear();
    term.clear();
    update();
}

