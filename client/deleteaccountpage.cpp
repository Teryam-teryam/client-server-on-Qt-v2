#include "deleteaccountpage.h"
#include "ui_deleteaccountpage.h"

DeleteAccountPage::DeleteAccountPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DeleteAccountPage)
{
    ui->setupUi(this);
}

DeleteAccountPage::~DeleteAccountPage()
{
    delete ui;
}

void DeleteAccountPage::on_signUpButton_clicked()
{
    emit showRegisterPage();
}


void DeleteAccountPage::on_signInButton_clicked()
{
    emit showLoginPage();
}


void DeleteAccountPage::on_deleteAccountButton_clicked()
{

}
