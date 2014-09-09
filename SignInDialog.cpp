#include "SignInDialog.h"
#include "ui_SignInDialog.h"

SignInDialog::SignInDialog(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SignInDialog)
{
    ui->setupUi(this);
}

SignInDialog::~SignInDialog()
{
    delete ui;
}
