#include "TimeSlot.h"
#include "ui_TimeSlot.h"

#include <QColor>
#include <QPalette>

TimeSlot::TimeSlot(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TimeSlot)
{
    ui->setupUi(this);
    setChildren();
}

TimeSlot::~TimeSlot()
{
    delete ui;
}

void TimeSlot::changeButtonColor(ColorButton *button, const QColor &color){
    QPalette pal;
    pal = button->palette();
    pal.setColor(QPalette::Button, color);
    button->setAutoFillBackground(true);
    button->setPalette(pal);
    button->update();
}

void TimeSlot::allDay(int day, int avail){

    QColor color;

    // Deterimine color
    if(avail == 0) {
        color = QColor(Qt::red);
    } else if(avail == 1) {
        color = QColor(Qt::yellow);
    } else if(avail == 2){
        color = QColor(Qt::green);
    } else {
        //invalid availability
    }

    // Determine day
    if(day == 0) {
        changeButtonColor(ui->buttonSun, color);
    } else if(day == 1) {
        changeButtonColor(ui->buttonMon, color);
    } else if(day == 2) {
        changeButtonColor(ui->buttonTues, color);
    } else if(day == 3) {
        changeButtonColor(ui->buttonWed, color);
    } else if(day == 4) {
        changeButtonColor(ui->buttonThur, color);
    } else if(day == 5) {
        changeButtonColor(ui->buttonFri, color);
    } else if(day == 6) {
        changeButtonColor(ui->buttonSat, color);
    } else {
        // invalid day
    }
}

void TimeSlot::allTime(int avail){
     QColor color;

    // Deterimine color
    if(avail == 0) {
        color = QColor(Qt::red);
    } else if(avail == 1) {
        color = QColor(Qt::yellow);
    } else if(avail == 2){
        color = QColor(Qt::green);
    } else {
        //invalid availability
    }

    //Apply changes
    foreach(ColorButton *child,children){
        changeButtonColor(child, color);
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
