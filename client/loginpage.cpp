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
    emit registerRequested();
}

void LoginPage::on_signInButton_clicked()
{
    QString login = ui->loginEdit->text().trimmed();
    QString password = ui->passwordEdit->text();

    if (login.isEmpty() || password.isEmpty())
    {
        ui->errorLabel->setText("Логин и/или пароль не должны быть пустыми");
        ui->errorLabel->setVisible(true);
        return;
    }
    ui->errorLabel->setVisible(false);
    emit loginRequested(login, password);
}

void LoginPage::on_deleteAccountButton_clicked()
{
    emit deleteAccountRequested();
}

void LoginPage::onLoginResult(bool success, const QString &errorMessage)
{
    if (!success)
    {
        ui->errorLabel->setText(errorMessage);
        ui->errorLabel->setVisible(true);
    }
    ui->errorLabel->setVisible(false);
}
