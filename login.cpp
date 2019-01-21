#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Login)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    ui->zhuce->hide();
    ui->exit->hide();
    ID = "Xianyu";
    PWD = "123456";
    mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("mydb.db");
    if(!mydb.open())
    {
        QMessageBox::warning(this,"提示","数据库打开失败");
        close();
    }
    myquery = mydb.exec("create table if not exists users (username,password)");
        myquery=mydb.exec("select * from users");
}

Login::~Login()
{
    delete ui;
}

void Login::on_pushButton_clicked()
{
    ui->zhuce->show();
    ui->denglu->hide();
    ui->exit->show();
    ui->anniu->hide();
}

void Login::on_exit_clicked()
{
    ui->zhuce->hide();
    ui->denglu->show();
    ui->anniu->show();
    ui->exit->hide();
}

void Login::on_dl_clicked()
{
    QString username=ui->yhm->text();
    QString password=ui->mm->text();
    if(username=="" || password==""){
        QMessageBox::warning(this,"提示","用户名或密码不能为空");
    }
    bool isexec=myquery.exec("select * from users where username='"+username+"' and password='"+password+"'");
    if(isexec){
        if(myquery.next()){
         QMessageBox::warning(this,"提示","登录成功");
         this->close();
        kz.show();
        }else{
            QMessageBox::warning(this,"提示","用户名不存在");
        }
    }else{
         QMessageBox::warning(this,"提示","命令执行失败");
    }
}

void Login::on_zc_clicked()
{
    QString username=ui->zcm->text();
    QString password1=ui->zcmm->text();
    QString password2=ui->qrmm->text();
    if(username=="" || password1=="" || password2==""){
        QMessageBox::warning(this,"提示","信息输入不完全");
        return;
    }
    if(password1!=password2){
        QMessageBox::warning(this,"提示","两次密码输入不一样");
        return;
    }
    bool isexec=myquery.exec("select * from users where username='"+username+"'");
    if(isexec){
        if(!myquery.next()){
            bool isexec=myquery.exec("insert into users (username,password) values ('"+username+"','"+password1+"')");
            if(isexec){
                QMessageBox::warning(this,"提示","注册成功");
            }else{
                 QMessageBox::warning(this,"提示","注册不成功，命令执行失败");
            }
        }else{
            QMessageBox::warning(this,"提示","用户名已经存在");
        }
    }else{
        QMessageBox::warning(this,"提示","命令执行失败");
    }
}
