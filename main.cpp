#include "alcooltest.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Alcooltest w;
    w.show();

    return a.exec();
}
