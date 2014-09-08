#ifndef CALENDARWEEKWIDGET_H
#define CALENDARWEEKWIDGET_H

#include <QWidget>
#include "TimeSlot.h"
#include <QButtonGroup>

namespace Ui {
class CalendarWeekWidget;
}

class CalendarWeekWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CalendarWeekWidget(QWidget *parent = 0);
    ~CalendarWeekWidget();

    int **getWeekAvail();

public slots:
    void updateAvail(int curAvail);

private:
    Ui::CalendarWeekWidget *ui;
    int avail;
    int **weekState;
    QList<TimeSlot*> timeSlots;
    QButtonGroup *dayGroup;
    QButtonGroup *timeGroup;

    void setTimeSlots();
    void setDayGroup();
    void setTimeGroup();

private slots:
    void handleDayClicked(int day);
    void handleTimeClicked(int id);
};

#endif // CALENDARWEEKWIDGET_H
