#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "book.h"
#include "mylist.h"
#include <QString>
#include "librarybook.h"
#include "change.h"




namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_actionSave_List_in_File_triggered();

    void on_actionRead_File_triggered();

    void on_actionChange_element_triggered();

    void seeCount();

private:
    Ui::MainWindow *ui;

    QString Buff;
    int i;
    std::ofstream File;
    std::ifstream FileToRead;
    change  w;





};

#endif // MAINWINDOW_H
