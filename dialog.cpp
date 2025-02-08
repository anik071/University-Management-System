#include "dialog.h"
#include "ui_dialog.h"
#include <QTimer>
Dialog::Dialog(int a,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    ui->pushButton->setVisible(false);
    if(a){
    ui->label->setText("Log in Successful !!");
    ui->label->setAlignment(Qt::AlignCenter);
    QTimer::singleShot(1000,this,&QDialog::close);
    }else{
        ui->label->setText("Invalid Username/Password.Try again Later");
        ui->label->setAlignment(Qt::AlignCenter);
        ui->pushButton->setVisible(true);

    }

}
Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_pushButton_clicked()
{
    QDialog::close();
}

