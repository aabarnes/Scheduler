#ifndef CALENDARWEEKWIDGET_H
#define CALENDARWEEKWIDGET_H

#include <QWidget>

namespace Ui {
class CalendarWeekWidget;
}

class CalendarWeekWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CalendarWeekWidget(QWidget *parent = 0);
    ~CalendarWeekWidget();

public slots:
    void updateAvail(int curAvail);

private:
    Ui::CalendarWeekWidget *ui;
    int avail;

};

#endif // CALENDARWEEKWIDGET_H
