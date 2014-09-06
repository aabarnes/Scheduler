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

signals:
    void changeColor(int day, int avail);

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
    void setUpDayGroup();
    void setUpTimeGroup();

private slots:
    void handleDayClicked(int day);
};

#endif // CALENDARWEEKWIDGET_H
