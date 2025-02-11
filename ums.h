#ifndef UMS_H
#define UMS_H

#include <QMainWindow>
#include"dialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class UMS; }
QT_END_NAMESPACE

class UMS : public QMainWindow
{
    Q_OBJECT

public:
    UMS(QWidget *parent = nullptr);
    ~UMS();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_lineEdit_returnPressed();

    void on_lineEdit_2_returnPressed();

    void on_lineEdit_3_returnPressed();

    void on_lineEdit_4_returnPressed();

    void read();

    
    void on_Dashboard_Admin_clicked();

    void on_Dashboard_Student_clicked();

    void on_Logut_1_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_14_clicked();

private:
    Ui::UMS *ui;
};
#endif // UMS_H
