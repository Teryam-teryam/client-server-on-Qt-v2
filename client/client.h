#ifndef CLIENT_H
#define CLIENT_H

#include <QMainWindow>
#include <QStackedWidget>
#include "loginpage.h"
#include "registerpage.h"
#include "deleteaccountpage.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Client; }
QT_END_NAMESPACE

class Client : public QMainWindow
{
    Q_OBJECT

public:
    Client(QWidget *parent = nullptr);
    ~Client();
private slots:
    // Отправка запросов на сервер
    void handleLoginRequested();
    void handleRegisterRequested();
    void handleDeleteAccountRequested();

    // Переключение страниц
    void showLoginPage();
    void showRegisterPage();
    void showDeleteAccountPage();
private:
    void setupUi();
    Ui::Client *ui;
    QStackedWidget *m_stackedWidget;
    LoginPage *m_loginPage;
    RegisterPage *m_registerPage;
    DeleteAccountPage *m_deleteAccountPage;


};
#endif // CLIENT_H
