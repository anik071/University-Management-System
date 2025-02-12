#include "ums.h"
#include "ui_ums.h"
#include<QMessageBox>
#include<QSqlQueryModel>

UMS::UMS(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::UMS)
{
    ui->setupUi(this);
ca

    ui->stackedWidget->setCurrentIndex(0);
}
 QString Users;
UMS::~UMS()
{
    delete ui;
}
void UMS::on_pushButton_clicked() //Administration Log-In Button
{
    ui->stackedWidget->setCurrentIndex(1);
    ui->lineEdit->setFocus();
    ui->lineEdit->setPlaceholderText("Enter Your Username");
    ui->lineEdit_2->setPlaceholderText("Enter Your Password");
    ui->lineEdit_2->setEchoMode(QLineEdit::Password);
}




void UMS::on_pushButton_2_clicked()//Student Log In-Button
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->lineEdit_3->setFocus();
    ui->lineEdit_3->setPlaceholderText("Enter Your Username");
    ui->lineEdit_4->setPlaceholderText("Enter Your Password");
    ui->lineEdit_4->setEchoMode(QLineEdit::Password);
}


void UMS::on_pushButton_3_clicked()//Exit Button
{
    QApplication::quit();
}


void UMS::on_pushButton_6_clicked() //Back Button From Administration page
{
 ui->stackedWidget->setCurrentIndex(0);
}


void UMS::on_pushButton_7_clicked()//Back Button From Student page
{
    ui->stackedWidget->setCurrentIndex(0);

}

void UMS::on_pushButton_4_clicked()// Log-In Button for Administration
{
    QString user=ui->lineEdit->text();      //Taking Input from line Editor

    QString pass=ui->lineEdit_2->text();
    Users=user;
    if(user.size()==0 or pass.size()==0){   //If username or password is longer than 0 charachter then it will work
        QMessageBox::critical(this,"Input Error","username/password can't be empty");
        return;
    }
    if(!connopen()){
        qDebug()<<"Failed to open";
        return ;
    }
    QSqlQuery qry;
    if(qry.exec("select * from faculty where username='"+user+"' and password='"+pass+"'")){
        if(qry.next()){
            Dialog *Log=new Dialog(1,this);
            Log->show();
            ui->lineEdit->clear();
            ui->lineEdit_2->clear();
            ui->stackedWidget->setCurrentIndex(3);
            ui->stackedWidget_2->setCurrentIndex(0);

        }else{
            Dialog *Log=new Dialog(0,this);
            Log->show();
        }

    }

}


void UMS::on_pushButton_5_clicked()//Log-In Button for Students
{
    QString user=ui->lineEdit_3->text();    //Same as on_pushButton_4_clicked

    QString pass=ui->lineEdit_4->text();
    Users=user;
    if(user.size()==0&&pass.size()==0){
        QMessageBox::critical(this,"Input Error","username/password can't be empty");
        return;
    }
    if(!connopen()){
        qDebug()<<"Failed to open";
        return ;
    }
    QSqlQuery qry;
    if(qry.exec("select * from student where username='"+user+"' and password='"+pass+"'")){
        if(qry.next()){
            Dialog *Log=new Dialog(1,this);
            Log->show();
            ui->lineEdit_3->clear();
            ui->lineEdit_4->clear();
            ui->stackedWidget->setCurrentIndex(4);
            ui->stackedWidget_3->setCurrentIndex(0);
        }else{
            Dialog *Log=new Dialog(0,this);
            Log->show();
        }

    }
}


void UMS::on_lineEdit_returnPressed()//pressing enter will set the cursor in next text box
{
    ui->lineEdit_2->setFocus();
}


void UMS::on_lineEdit_2_returnPressed()//pressing enter will set the cursor in Button
{
    on_pushButton_4_clicked();
}


void UMS::on_lineEdit_3_returnPressed()//pressing enter will set the cursor in next text box
{
     ui->lineEdit_4->setFocus();
}


void UMS::on_lineEdit_4_returnPressed()//pressing enter will set the cursor in Button
{
    on_pushButton_5_clicked();
}






void UMS::on_Dashboard_Admin_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(0);
}



void UMS::on_Logut_1_clicked()
{

    ui->stackedWidget->setCurrentIndex(0);
}


void UMS::on_pushButton_12_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void UMS::on_pushButton_14_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(1);
    if(!connopen()){
        qDebug()<<"Failed to open";
        return ;
    }
    QSqlQuery qry;
    if(qry.exec("select * from faculty where username='"+Users+"'")){
        if(qry.next()){
            ui->Admin_name->setText(qry.value(0).toString());
            ui->Admin_name->setReadOnly(true);
            ui->Admin_email->setText(qry.value(8).toString());
            ui->Admin_email->setReadOnly(true);
            ui->Admin_contact->setText(qry.value(7).toString());
            ui->Admin_contact->setReadOnly(true);
            ui->Admin_designation->setText(qry.value(9).toString());
            ui->Admin_designation->setReadOnly(true);
            ui->Admin_blood->setText(qry.value(4).toString());
            ui->Admin_blood->setReadOnly(true);
            ui->Admin_ed->setText(qry.value(6).toString());
            ui->Admin_ed->setReadOnly(true);
        }
}}




void UMS::on_pushButton_17_clicked()
{
    ui->stackedWidget_2->setCurrentIndex(2);
}


void UMS::on_Add
