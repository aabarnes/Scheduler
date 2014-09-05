#include "schedulerdialog.h"
#include "ui_schedulerdialog.h"

SchedulerDialog::SchedulerDialog(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SchedulerDialog),
    radioGroup(new QButtonGroup)
{
    ui->setupUi(this);

    ui->widgetTab->setCurrentIndex(0);


}

SchedulerDialog::~SchedulerDialog()
{
    delete ui;
}
