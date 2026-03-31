#include "client.h"
#include "ui_client.h"
#include <QMessageBox>
#include <QTimer>
Client::Client(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Client)
{
    ui->setupUi(this);
    setupUi();
}

Client::~Client()
{
    delete ui;
}

void Client::setupUi()
{
    setWindowTitle("===setupUI===");
    resize(500, 600);

    m_loginPage = new LoginPage(this);
    setCentralWidget(m_loginPage);
    connect(m_loginPage, &LoginPage::loginRequested ,this, &Client::on_LoginPageRequested);
    connect(m_loginPage, &LoginPage::registerRequested, this, &Client::on_RegisterRequested);
    connect(m_loginPage, &LoginPage::deleteAccountRequested, this, &Client::on_DeleteAccountRequested);
}
void Client::on_LoginPageRequested(const QString &login, const QString &password)
{

}

void Client::on_RegisterRequested()
{

}

void Client::on_DeleteAccountRequested()
{

}
