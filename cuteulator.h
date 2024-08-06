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

private:
    Ui::Cuteulator *ui;
};
#endif // CUTEULATOR_H
