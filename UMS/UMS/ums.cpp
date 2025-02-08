#include "ums.h"
#include "ui_ums.h"
#include<bits/stdc++.h>
#include<QString>
#include<QFile>
#include<QDebug>
#include<QCoreApplication>

using namespace std;

map<string,string>admin={{"admin","admin"}},student={{"root","root"}};
UMS::UMS(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::UMS)
{
    ui->setupUi(this);
       read();
    ui->stackedWidget->setCurrentIndex(0);
}

UMS::~UMS()
{
    delete ui;
}
void UMS::read(){
    QFile file(":/resources/login/facultyLogin.txt");

        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            //qDebug() << "Error: Cannot open file from resources!";
            return;
        }

        QTextStream in(&file);
        while (!in.atEnd()) {
            QString key = in.readLine();
            QString value = in.readLine();
            string keys=key.toStdString(),values=value.toStdString();
            admin.insert(pair<string,string>(keys,values));
            //qDebug() << "Key:" << key << ", Value:" << value;
        }
        file.close();
        QFile file1(":/resources/login/studentLogin.txt");

            if (!file1.open(QIODevice::ReadOnly | QIODevice::Text)) {
                //qDebug() << "Error: Cannot open file from resources!";
                return;
            }

            QTextStream in1(&file1);
            while (!in1.atEnd()) {
                QString key1 = in1.readLine();
                QString value1 = in1.readLine();
                string keys1=key1.toStdString(),values1=value1.toStdString();
                student.insert(pair<string,string>(keys1,values1));
                //qDebug() << "Key:" << key << ", Value:" << value;
            }
            file1.close();


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
    string username=user.toStdString();     //Converting Qstring to c++ String
    QString pass=ui->lineEdit_2->text();
    string password=pass.toStdString();
    if(username.size()>0&&password.size()>0){   //If username or password is longer than 0 charachter then it will work
    if(admin[username]==password){          //If username matches its corresponding password then it will take to the next page
        Dialog *Log=new Dialog(1,this);
        Log->show();
        ui->stackedWidget->setCurrentIndex(3);  //Used to changed widget screen
    }else{
        Dialog *Log=new Dialog(0,this);
        Log->show();
    }}
}


void UMS::on_pushButton_5_clicked()//Log-In Button for Students
{
    QString user=ui->lineEdit_3->text();    //Same as on_pushButton_4_clicked
    string username=user.toStdString();
    QString pass=ui->lineEdit_4->text();
    string password=pass.toStdString();
    if(username.size()>0&&password.size()>0){
    if(student[username]==password){
        Dialog *Log=new Dialog(1,this);
        Log->show();
        ui->stackedWidget->setCurrentIndex(4);
    }else{
        Dialog *Log=new Dialog(0,this);
        Log->show();
    }}
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


void UMS::on_AddStudent_clicked()
{

}

