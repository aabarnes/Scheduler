#include "CalendarWeekWidget.h"
#include "ui_CalendarWeekWidget.h"

CalendarWeekWidget::CalendarWeekWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CalendarWeekWidget),
    avail(-1),
    weekState(new int*[24]),
    dayGroup(new QButtonGroup),
    timeGroup(new QButtonGroup)
{
    ui->setupUi(this);

    setTimeSlots();
    setDayGroup();
    setTimeGroup();

    connect(dayGroup, SIGNAL(buttonClicked(int)), this, SLOT(handleDayClicked(int)));
    connect(timeGroup, SIGNAL(buttonClicked(int)), this, SLOT(handleTimeClicked(int)));
    connect(ui->buttonAll, SIGNAL(clicked()), this, SLOT(handleAllClicked()));
}

CalendarWeekWidget::~CalendarWeekWidget()
{
    delete ui;
}

int **CalendarWeekWidget::getWeekAvail(){
    int i = -1;
    foreach(TimeSlot *time, timeSlots){
        weekState[++i] = time->getTimeAvail();
    }

    return weekState;
}

void CalendarWeekWidget::updateAvail(int curAvail){
    avail = curAvail;
}

void CalendarWeekWidget::setTimeSlots(){
    timeSlots.append(ui->week12A);
    timeSlots.append(ui->week1A);
    timeSlots.append(ui->week2A);
    timeSlots.append(ui->week3A);
    timeSlots.append(ui->week4A);
    timeSlots.append(ui->week5A);
    timeSlots.append(ui->week6A);
    timeSlots.append(ui->week7A);
    timeSlots.append(ui->week8A);
    timeSlots.append(ui->week9A);
    timeSlots.append(ui->week10A);
    timeSlots.append(ui->week11A);
    timeSlots.append(ui->week12P);
    timeSlots.append(ui->week1P);
    timeSlots.append(ui->week2P);
    timeSlots.append(ui->week3P);
    timeSlots.append(ui->week4P);
    timeSlots.append(ui->week5P);
    timeSlots.append(ui->week6P);
    timeSlots.append(ui->week7P);
    timeSlots.append(ui->week8P);
    timeSlots.append(ui->week9P);
    timeSlots.append(ui->week10P);
    timeSlots.append(ui->week11P);
}

void CalendarWeekWidget::setDayGroup(){
    dayGroup->addButton(ui->buttonSun, 0);
    dayGroup->addButton(ui->buttonMon, 1);
    dayGroup->addButton(ui->buttonTues, 2);
    dayGroup->addButton(ui->buttonWed, 3);
    dayGroup->addButton(ui->buttonThurs, 4);
    dayGroup->addButton(ui->buttonFri, 5);
    dayGroup->addButton(ui->buttonSat, 6);
}

void CalendarWeekWidget::setTimeGroup(){
    timeGroup->addButton(ui->button12A, 0);
    timeGroup->addButton(ui->button1A, 1);
    timeGroup->addButton(ui->button2A, 2);
    timeGroup->addButton(ui->button3A, 3);
    timeGroup->addButton(ui->button4A, 4);
    timeGroup->addButton(ui->button5A, 5);
    timeGroup->addButton(ui->button6A, 6);
    timeGroup->addButton(ui->button7A, 7);
    timeGroup->addButton(ui->button8A, 8);
    timeGroup->addButton(ui->button9A, 9);
    timeGroup->addButton(ui->button10A, 10);
    timeGroup->addButton(ui->button11A, 11);
    timeGroup->addButton(ui->button12P, 12);
    timeGroup->addButton(ui->button1P, 13);
    timeGroup->addButton(ui->button2P, 14);
    timeGroup->addButton(ui->button3P, 15);
    timeGroup->addButton(ui->button4P, 16);
    timeGroup->addButton(ui->button5P, 17);
    timeGroup->addButton(ui->button6P, 18);
    timeGroup->addButton(ui->button7P, 19);
    timeGroup->addButton(ui->button8P, 20);
    timeGroup->addButton(ui->button9P, 21);
    timeGroup->addButton(ui->button10P, 22);
    timeGroup->addButton(ui->button11P, 23);
}

void CalendarWeekWidget::handleDayClicked(int day){
    for(int i = 0; i < timeSlots.size(); ++i){
        timeSlots.at(i)->allDay(day, avail);
    }
}

void CalendarWeekWidget::handleTimeClicked(int id){
    timeSlots.at(id)->allTime(avail);
}

void CalendarWeekWidget::handleAllClicked(){
    for(int i = 0; i < timeSlots.size(); ++i){
        timeSlots.at(i)->allTime(avail);
    }
}
