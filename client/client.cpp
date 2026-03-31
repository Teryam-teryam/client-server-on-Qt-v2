//Все сигналы для переключения страниц названы showXxxPage()
//Сигналы для выполнения действий (отправка запросов на сервер) названы xxxRequested()
//В главном окне слоты обработки действий - handleXxxRequest(), а для переключения страниц - showXxxPage()

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
    //setWindowTitle("===setupUI===");
    resize(500, 600);

    // Создаём стек
    m_stackedWidget = new QStackedWidget(this);
    setCentralWidget(m_stackedWidget);

    // Создаём страницы
    m_loginPage = new LoginPage(this);
    m_registerPage = new RegisterPage(this);
    m_deleteAccountPage = new DeleteAccountPage(this);

    // Добавляем страницы в стек (порядок не важен, переключаем по указателю)
    m_stackedWidget->addWidget(m_loginPage);
    m_stackedWidget->addWidget(m_registerPage);
    m_stackedWidget->addWidget(m_deleteAccountPage);

    // По умолчанию показываем страницу входа
    m_stackedWidget->setCurrentWidget(m_loginPage);

    // Подключаем сигналы от LoginPage
    connect(m_loginPage, &LoginPage::loginRequested ,this, &Client::handleLoginRequested);
    connect(m_loginPage, &LoginPage::showRegisterPage, this, &Client::showRegisterPage);
    connect(m_loginPage, &LoginPage::showDeleteAccountPage, this, &Client::showDeleteAccountPage);

    // Подключаем сигналы от RegisterPage
    connect(m_registerPage, &RegisterPage::registerRequested, this, &Client::handleRegisterRequested);
    connect(m_registerPage, &RegisterPage::showLoginPage, this, &Client::showLoginPage);
    connect(m_registerPage, &RegisterPage::showDeleteAccountPage, this, &Client::showDeleteAccountPage);

    // Подключаем сигналы от DeleteAccountPage
    connect(m_deleteAccountPage, &DeleteAccountPage::deleteAccountRequested ,this, &Client::handleDeleteAccountRequested);
    connect(m_deleteAccountPage, &DeleteAccountPage::showRegisterPage, this, &Client::showRegisterPage);
    connect(m_deleteAccountPage, &DeleteAccountPage::showLoginPage, this, &Client::showLoginPage);
}
void Client::handleRegisterRequested()
{

}

void Client::handleLoginRequested()
{

}

void Client::handleDeleteAccountRequested()
{

}
void Client::showLoginPage()        {m_stackedWidget->setCurrentWidget(m_loginPage);}
void Client::showRegisterPage()     {m_stackedWidget->setCurrentWidget(m_registerPage);}
void Client::showDeleteAccountPage() {m_stackedWidget->setCurrentWidget(m_deleteAccountPage);}

