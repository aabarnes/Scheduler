#include "schedulerdialog.h"
#include "ui_schedulerdialog.h"

SchedulerDialog::SchedulerDialog(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SchedulerDialog),
    radioGroup(new QButtonGroup)
{
    ui->setupUi(this);

    ui->widgetTab->setCurrentIndex(0);

    radioGroup->addButton(ui->radioAvailable, 3);
    radioGroup->addButton(ui->radioNotPreferred, 2);
    radioGroup->addButton(ui->radioUnavailable, 1);

    connect(radioGroup, SIGNAL(buttonClicked(int)), ui->widgetWeek, SLOT(updateAvail(int)));
    ui->radioUnavailable->click();
}

SchedulerDialog::~SchedulerDialog()
{
    delete ui;
}
