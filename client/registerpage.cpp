#include "registerpage.h"
#include "ui_registerpage.h"

RegisterPage::RegisterPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RegisterPage)
{
    ui->setupUi(this);
}

RegisterPage::~RegisterPage()
{
    delete ui;
}

void RegisterPage::on_signUpButton_clicked()
{
}


void RegisterPage::on_signInButton_clicked()
{
    emit showLoginPage();
}


void RegisterPage::on_deleteAccountButton_clicked()
{
    emit showDeleteAccountPage();
}

