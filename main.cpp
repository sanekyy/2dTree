#include <QApplication>
#include <QtWidgets/QWidget>
#include "workDir/widgets/MainWindow.h"
#include "Statistic.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    if(false){
        MainWindow mainWindow;
    mainWindow.show();

        return a.exec();
    } else {
        (new Statistic())->runBalanced();
        return 0;
    }
}