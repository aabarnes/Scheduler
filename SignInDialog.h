#ifndef SIGNINDIALOG_H
#define SIGNINDIALOG_H

#include <QWidget>

namespace Ui{
    class SignInDialog;
}

class SignInDialog : public QWidget
{
    Q_OBJECT

public:
    SignInDialog(QWidget *parent = 0);

private:
    Ui::SignInDialog ui;

    // Unimplemented
    SignInDialog(const SignInDialog&);
};

#endif // SIGNINDIALOG_H
