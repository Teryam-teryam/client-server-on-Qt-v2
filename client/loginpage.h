#ifndef LOGINPAGE_H
#define LOGINPAGE_H

#include <QWidget>

namespace Ui{ class LoginPage; }

class LoginPage : public QWidget
{
    Q_OBJECT
public:
    explicit LoginPage(QWidget *parent = nullptr);
    ~LoginPage();
signals:
    void loginRequested(const QString &login, const QString &password);
    void registerRequested();
    void deleteAccountRequested();
public slots:
    void onLoginResult(bool success, const QString &errorMessage);
private slots:
    void on_signUpButton_clicked();
    void on_signInButton_clicked();
    void on_deleteAccountButton_clicked();
private:
    Ui::LoginPage *ui;
};

#endif // LOGINPAGE_H
