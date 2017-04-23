#ifndef CHANGE_H
#define CHANGE_H

#include <QDialog>

namespace Ui {
class change;
}

class change : public QDialog
{
    Q_OBJECT

public:
    explicit change(QWidget *parent = 0);
    ~change();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::change *ui;
    int nOfEl;
};

#endif // CHANGE_H
