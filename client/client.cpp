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

    // Создаём стек
    m_stackedWidget = new QStackedWidget(this);
    setCentralWidget(m_stackedWidget);
    // Создаём страницы
    m_loginPage = new LoginPage(this);
    m_registerPage = new RegisterPage(this);
    // Добавляем страницы в стек (порядок не важен, переключаем по указателю)
    m_stackedWidget->addWidget(m_loginPage);
    m_stackedWidget->addWidget(m_registerPage);
    // По умолчанию показываем страницу входа
    m_stackedWidget->setCurrentWidget(m_loginPage);

    // Подключаем сигналы от LoginPage
    connect(m_loginPage, &LoginPage::loginRequested ,this, &Client::on_LoginPageRequested);
    connect(m_loginPage, &LoginPage::registerRequested, this, &Client::showRegisterPage);
    connect(m_loginPage, &LoginPage::deleteAccountRequested, this, &Client::on_DeleteAccountRequested);
    // Подключаем сигналы от RegisterPage
    connect(m_registerPage, &RegisterPage::backToLoginPage, this, &Client::showLoginPage);
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
void Client::showLoginPage()
{
    m_stackedWidget->setCurrentWidget(m_loginPage);
}
void Client::showRegisterPage()
{
    m_stackedWidget->setCurrentWidget(m_registerPage);
}
