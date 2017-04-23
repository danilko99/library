#include "change.h"
#include "ui_change.h"
#include "mainwindow.h"
#include <QMessageBox>

extern myList List;

change::change(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::change)
{
    ui->setupUi(this);
}

change::~change()
{
    delete ui;
}

void change::on_pushButton_2_clicked()
{
    nOfEl = ui->lineEdit_5->text().toInt();
    if (!(List.size() > nOfEl))
    {
        ui->textBrowser->setText("Incorrect input!");
        ui->pushButton->setEnabled(false);
    }
    else
    {
        ui->textBrowser->setText(QString::fromStdString(List.getBook(nOfEl)));
        ui->pushButton->setEnabled(true);

        switch (List.TypeOfElement(nOfEl))

        {
        case 0:

            ui->lineEdit_4->setEnabled(false);
            ui->label_4->setEnabled(false);
            ui->label_5->setEnabled(false);
            ui->radioButton->setEnabled(false);
            ui->radioButton_2->setEnabled(false);

            break;

        case 1:

            ui->lineEdit_4->setEnabled(true);
            ui->label_4->setEnabled(true);
            ui->label_5->setEnabled(true);
            ui->radioButton->setEnabled(true);
            ui->radioButton_2->setEnabled(true);

            break;
        }
    }

}


void change::on_pushButton_clicked()
{
    bool flag_;
    QMessageBox *closeMessBox = new QMessageBox(QMessageBox::Information,tr("Error!"),tr("Are you sure that your inputs are correct?"),
    QMessageBox::Ok);

    if  (ui->lineEdit_2->text().isEmpty()||ui->lineEdit->text().isEmpty())//проверка на корректность введенных данных
    {

        closeMessBox->exec();

    }

    else
    {
        switch (List.TypeOfElement(nOfEl))//тип элемента в списке по номеру

        {
        case 0: //родитель

            List.setAllInfo(nOfEl,ui->lineEdit->text().toStdString(),ui->lineEdit_2->text().toStdString(),ui->lineEdit_3->text().toInt(),ui->lineEdit_4->text().toInt(),flag_);
            break;

        case 1: //наследник

            if (ui->radioButton_2->isChecked())  flag_=false;
            else
                flag_=true;

            List.setAllInfo(nOfEl,ui->lineEdit->text().toStdString(),ui->lineEdit_2->text().toStdString(),ui->lineEdit_3->text().toInt(),ui->lineEdit_4->text().toInt(),flag_);
            break;
        }
        ui->textBrowser->setText(QString::fromStdString(List.getBook(nOfEl)));
        ui->radioButton->setChecked(false);
        ui->radioButton_2->setChecked(false);
    }
    delete  closeMessBox;


}





void change::on_pushButton_3_clicked()
{
    QMessageBox *closeMessBox = new QMessageBox(QMessageBox::Information,tr("Exit"),tr("Are you sure?"),
    QMessageBox::Ok| QMessageBox::Cancel);
    if(closeMessBox->exec() == QMessageBox::Ok)
       {
           this->close();
       }
}
