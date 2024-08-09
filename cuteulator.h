#ifndef CUTEULATOR_H
#define CUTEULATOR_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class Cuteulator;
}
QT_END_NAMESPACE

class Cuteulator : public QMainWindow
{
    Q_OBJECT

public:
    Cuteulator(QWidget *parent = nullptr);
    ~Cuteulator();

private slots:
    void on_btn0_clicked();

    void on_btn1_clicked();

    void on_btn2_clicked();

    void on_btn3_clicked();

    void on_btn4_clicked();

    void on_btn5_clicked();

    void on_btn6_clicked();

    void on_btn7_clicked();

    void on_btn8_clicked();

    void on_btn9_clicked();

private:
    Ui::Cuteulator *ui;
    void update();
};
#endif // CUTEULATOR_H
