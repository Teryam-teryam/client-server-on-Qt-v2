#ifndef CLIENT_H
#define CLIENT_H

#include <QMainWindow>
#include "loginpage.h"

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
private:
    void setupUi();
    Ui::Client *ui;
    LoginPage *m_loginPage;
};
#endif // CLIENT_H
