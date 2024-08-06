#include "cuteulator.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Cuteulator w;
    w.show();
    return a.exec();
}
