#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox.h"
#include "mythread.h"
#include <QMutex>
#include <QFuture>
#include <QtConcurrent/QtConcurrent>


extern myList List;

QMutex Mutex;

myThread Sync_;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    Sync_.start();
    ui->setupUi(this);
    QObject::connect(&Sync_,SIGNAL(Signal(int)),this, SLOT(seeCount()));
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked()// Закрываем mainWindow + messagebox
{
    QMessageBox *closeMessBox = new QMessageBox(QMessageBox::Information,tr("Exit"),tr("Are you sure?"),
    QMessageBox::Ok| QMessageBox::Cancel);
    if(closeMessBox->exec() == QMessageBox::Ok)
       {
           this->close();
       }

    delete  closeMessBox;
    this->close();
}


void MainWindow::on_pushButton_2_clicked()//добавление нового элемента в список
{
    QMessageBox *closeMessBox = new QMessageBox(QMessageBox::Information,tr("Error!"),tr("Are you sure that your inputs are correct?"),
    QMessageBox::Ok);

    std::shared_ptr<book> bk = std::make_shared<book>( );
    std::shared_ptr<libraryBook> lbk = std::make_shared<libraryBook>( );

    if  ((bk->setYear(ui->lineEdit_3->text().toInt())==0) &&(closeMessBox->exec() == QMessageBox::Ok))//проверка на корректность введенных данных
    {
    }

    else
    {
    bk->setName(ui->lineEdit->text().toStdString());
    bk->setAuthor(ui->lineEdit_2->text().toStdString());
    bk->setYear(ui->lineEdit_3->text().toInt());

    if (ui->lineEdit_4->text().isEmpty())
    {

        Mutex.lock();
              QFuture<void> Add = QtConcurrent::run(push_back, &List, bk);//запись родителя
              Add.waitForFinished();
        Mutex.unlock();
        //List.push_back(bk); //записываем в список информацию о родителе (книга),
                                                                //если не заполены поля наследника
    }
    else
    {
        lbk->setName(ui->lineEdit->text().toStdString());
        lbk->setAuthor(ui->lineEdit_2->text().toStdString());
        lbk->setYear(ui->lineEdit_3->text().toInt());
        lbk->setSerNum(ui->lineEdit_4->text().toInt());
        if (ui->radioButton->isChecked())  lbk->setFlag(false);
        else
            lbk->setFlag(true);

        Mutex.lock();//использование мьютекса
              QFuture<void> Add = QtConcurrent::run(push_back, &List, lbk);//запись наследника
              Add.waitForFinished();
        Mutex.unlock();

       // List.push_back(lbk);//записываем в список информацию о наследнике (библиотечная книга)
    }

    ui->textBrowser->setPlainText(QString::fromStdString (List.getAllInfo()));
//    ui->lineEdit->clear();
//    ui->lineEdit_2->clear();
//    ui->lineEdit_3->clear();


    }
    if (!List.empty())
    {

        ui->pushButton_3->setEnabled(true);
        ui->pushButton_4->setEnabled(true);
        std::string buff = "Book - " + std::to_string(List.countOfPrnt()) + " Library Book - " + std::to_string(List.countOfChld());
        ui->statusBar->showMessage(QString::fromStdString(buff), 5000);
    }

}

void MainWindow::on_pushButton_3_clicked()//удаление первого элемента из списка
{

    if (List.size()!=0)
    {
     Mutex.lock();
          QFuture<void> Add = QtConcurrent::run(pop_front, &List);//удаление элемента
          Add.waitForFinished();
     Mutex.unlock();
    //List.pop_front();
    ui->textBrowser->setPlainText(QString::fromStdString (List.getAllInfo()));
    }
    else ui->statusBar->showMessage("List is empty!", 5000);

}

void MainWindow::on_pushButton_4_clicked()//удаление последнего элемента из списка
{
    if (List.size()!=0)
    {        
    Mutex.lock();
          QFuture<void> Add = QtConcurrent::run(pop_back, &List);//удаление элемента
          Add.waitForFinished();
    Mutex.unlock();
    //List.pop_back();
    ui->textBrowser->setPlainText(QString::fromStdString (List.getAllInfo()));
    }
    else ui->statusBar->showMessage("List is empty!", 5000);
}

void MainWindow::on_actionSave_List_in_File_triggered()//запись листа в файл
{
    List.saveListToFile("save.cpp");
    ui->statusBar->showMessage("List recorded in a file  with name save.txt", 5000);
}

void MainWindow::on_actionRead_File_triggered()
{
    List.readListFromFile("book.txt");

    if (List.size()!=0)
    {
//       ui->textBrowser->setPlainText(QString::fromStdString (List.getAllInfo()));
//        std::string buff = std::to_string(List.readListFromFile("book.txt"));//количесвто строк в файле

        ui->textBrowser->setPlainText(QString::fromStdString (List.getAllInfo()));

        ui->pushButton_3->setEnabled(true);
        ui->pushButton_4->setEnabled(true);

        std::string buff = "Count of Book - " + std::to_string(List.countOfPrnt()) + ", Library Book - " + std::to_string(List.countOfChld());
        ui->statusBar->showMessage("List loaded from a file book.txt  "+QString::fromStdString(buff), 8000);
    }


}



void MainWindow::on_actionChange_element_triggered()
{
    w.show();
}


void MainWindow::seeCount()
{
    std::string buff = "Count of Book - " + std::to_string(List.countOfPrnt()) + ", Library Book - " + std::to_string(List.countOfChld());
    ui->statusBar->showMessage(QString::fromStdString(buff), 8000);
}
