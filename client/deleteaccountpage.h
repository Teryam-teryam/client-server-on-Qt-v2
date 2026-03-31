#ifndef DELETEACCOUNTPAGE_H
#define DELETEACCOUNTPAGE_H

#include <QWidget>

namespace Ui {
class DeleteAccountPage;
}

class DeleteAccountPage : public QWidget
{
    Q_OBJECT

public:
    explicit DeleteAccountPage(QWidget *parent = nullptr);
    ~DeleteAccountPage();

signals:
    void deleteAccountRequested();
    void showRegisterPage();
    void showLoginPage();

private slots:
    void on_signUpButton_clicked();
    void on_signInButton_clicked();
    void on_deleteAccountButton_clicked();


private:
    Ui::DeleteAccountPage *ui;
};

#endif // DELETEACCOUNTPAGE_H
