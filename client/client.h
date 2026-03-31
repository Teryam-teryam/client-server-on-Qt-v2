#ifndef CLIENT_H
#define CLIENT_H

#include <QMainWindow>
#include <QStackedWidget>
#include "loginpage.h"
#include "registerpage.h"

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
    void on_LoginPageRequested(const QString &login, const QString &password);
    void on_RegisterRequested();
    void on_DeleteAccountRequested();

    void showLoginPage();
    void showRegisterPage();
private:
    void setupUi();
    Ui::Client *ui;
    QStackedWidget *m_stackedWidget;
    LoginPage *m_loginPage;
    RegisterPage *m_registerPage;


};
#endif // CLIENT_H
