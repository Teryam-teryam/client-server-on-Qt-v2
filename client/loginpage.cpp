#include "loginpage.h"
#include "ui_loginpage.h"
#include <QPushButton>
LoginPage::LoginPage(QWidget *parent)
    : QWidget{parent}, ui(new Ui::LoginPage)
{
    ui->setupUi(this);

    connect(ui->signUpButton, &QPushButton::clicked, this, &LoginPage::on_signUpButton_clicked);
    connect(ui->signInButton, &QPushButton::clicked, this, &LoginPage::on_signInButton_clicked);
    connect(ui->deleteAccountButton, &QPushButton::clicked, this, &LoginPage::on_deleteAccountButton_clicked);
}

LoginPage::~LoginPage(){ delete ui; }

void LoginPage::on_signUpButton_clicked()
{
    emit showRegisterPage();
}

void LoginPage::on_signInButton_clicked()
{
    emit loginRequested();
}

void LoginPage::on_deleteAccountButton_clicked()
{
    emit showDeleteAccountPage();
}
