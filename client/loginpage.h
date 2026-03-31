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
    void loginRequested();
    void registerRequested();
    void showRegisterPage();
    void showDeleteAccountPage();

private slots:
    void on_signUpButton_clicked();
    void on_signInButton_clicked();
    void on_deleteAccountButton_clicked();
private:
    Ui::LoginPage *ui;
};

#endif // LOGINPAGE_H
