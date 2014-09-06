#include "TimeSlot.h"
#include "ui_TimeSlot.h"

#include <QColor>
#include <QPalette>

TimeSlot::TimeSlot(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TimeSlot),
    state(new int[7])
{
    ui->setupUi(this);

    setChildren();
}

TimeSlot::~TimeSlot()
{
    delete ui;
}

int *TimeSlot::getTimeAvail(){
    int i = -1;
    foreach(ColorButton *child, children){
        state[++i] = child->getColorState();
    }
    return state;
}

void TimeSlot::allDay(int day, int avail){
    ColorButton *button;

    // Determine day
    if(day == 0) {
        button = children.at(0);
    } else if(day == 1) {
        button = children.at(1);
    } else if(day == 2) {
        button = children.at(2);
    } else if(day == 3) {
        button = children.at(3);
    } else if(day == 4) {
        button = children.at(4);
    } else if(day == 5) {
        button = children.at(5);
    } else if(day == 6) {
        button = children.at(6);
    } else {
        // invalid day
    }
    button->changeColor(avail);
}

void TimeSlot::allTime(int avail){
    foreach(ColorButton *child, children){
        child->changeColor(avail);
    }
}

void TimeSlot::setChildren(){
    if(children.isEmpty()){
        children.append(ui->buttonSun);
        children.append(ui->buttonMon);
        children.append(ui->buttonTues);
        children.append(ui->buttonWed);
        children.append(ui->buttonThur);
        children.append(ui->buttonFri);
        children.append(ui->buttonSat);
    }
}
