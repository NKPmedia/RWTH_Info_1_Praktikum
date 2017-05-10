#include "mainwindow.h"
#include <QApplication>

/**
 * @brief starts the GUI
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
