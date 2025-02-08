#include "ums.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    UMS w;
    w.show();
    return a.exec();
}
