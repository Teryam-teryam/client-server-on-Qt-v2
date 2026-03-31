#ifndef REGISTERPAGE_H
#define REGISTERPAGE_H

#include <QWidget>

namespace Ui{ class RegisterPage; }

class RegisterPage : public QWidget
{
    Q_OBJECT

public:
    explicit RegisterPage(QWidget *parent = nullptr);
    ~RegisterPage();

signals:
    void registerRequested();
    void showLoginPage();
    void showDeleteAccountPage();
private slots:
    void on_signUpButton_clicked();
    void on_signInButton_clicked();
    void on_deleteAccountButton_clicked();


private:
    Ui::RegisterPage *ui;
};

#endif // REGISTERPAGE_H
