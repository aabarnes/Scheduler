#include "schedulerdialog.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SchedulerDialog w;
    w.show();
    
    return a.exec();
}
