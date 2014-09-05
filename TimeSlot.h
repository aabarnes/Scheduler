#ifndef TIMESLOT_H
#define TIMESLOT_H

#include "ColorButton.h"

namespace Ui {
class TimeSlot;
}

class TimeSlot : public QWidget
{
    Q_OBJECT
    
public:
    explicit TimeSlot(QWidget *parent = 0);
    ~TimeSlot();

public slots:
    void allTime(int avail);
    void allDay(int day, int avail);
    
private:
    Ui::TimeSlot *ui;
    QList<ColorButton*> children;

    void changeButtonColor(ColorButton *button, const QColor &color);
    void setChildren();

    //Unimplemented
    TimeSlot(const TimeSlot&);
};

#endif // TIMESLOT_H
