#include "CalendarWeekWidget.h"
#include "ui_CalendarWeekWidget.h"

CalendarWeekWidget::CalendarWeekWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CalendarWeekWidget),
    avail(-1)
{
    ui->setupUi(this);
}

CalendarWeekWidget::~CalendarWeekWidget()
{
    delete ui;
}

void CalendarWeekWidget::updateAvail(int curAvail){
    avail = curAvail;
}
