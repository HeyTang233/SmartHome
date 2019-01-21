#ifndef LOGIN_H
#define LOGIN_H
#include <QMessageBox>
#include <QDialog>
#include "kongzhi.h"
#include <QSqlDatabase>
#include <QSqlQuery>
namespace Ui {
class Login;
}

class Login : public QDialog
{
    Q_OBJECT
    
public:
    explicit Login(QWidget *parent = 0);
    ~Login();
    QSqlDatabase mydb;
    QSqlQuery myquery;
    QString ID,PWD;
    Kongzhi kz;
private slots:

    void on_pushButton_clicked();

    void on_exit_clicked();

    void on_dl_clicked();

    void on_zc_clicked();

private:
    Ui::Login *ui;
};

#endif // LOGIN_H
