#include <QApplication>
#include <QtWidgets/QWidget>
#include "workDir/widgets/MainWindow.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow mainWindow;
    mainWindow.show();

    return a.exec();
}