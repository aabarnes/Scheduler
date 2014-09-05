#ifndef SCHEDULERDIALOG_H
#define SCHEDULERDIALOG_H

#include <QMainWindow>
#include <QButtonGroup>

namespace Ui {
class SchedulerDialog;
}

class SchedulerDialog : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit SchedulerDialog(QWidget *parent = 0);
    ~SchedulerDialog();

private:
    Ui::SchedulerDialog *ui;
    QButtonGroup *radioGroup;
};

#endif // SCHEDULERDIALOG_H
