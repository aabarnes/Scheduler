#include "schedulerdialog.h"
#include "ui_schedulerdialog.h"

#include "CommonEnums.h"

SchedulerDialog::SchedulerDialog(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SchedulerDialog),
    radioGroup(new QButtonGroup)
{
    ui->setupUi(this);

    ui->widgetTab->setCurrentIndex(0);

    radioGroup->addButton(ui->radioAvailable, Availability::AVAILABLE);
    radioGroup->addButton(ui->radioNotPreferred, Availability::NOTPREFFERED);
    radioGroup->addButton(ui->radioUnavailable, Availability::UNAVAILABLE);

    connect(radioGroup, SIGNAL(buttonClicked(int)), ui->widgetWeek, SLOT(updateAvail(int)));
    ui->radioUnavailable->click();

    connect(ui->buttonSubmit, SIGNAL(clicked()), this, SLOT(requestCalendar()));
}

SchedulerDialog::~SchedulerDialog()
{
    delete ui;
}

void SchedulerDialog::requestCalendar(){

    //if signed in
        int **calendar = ui->widgetWeek->getWeekAvail();
    //  send calendar to user profile
    //if not signed in prompt for sign in
}
