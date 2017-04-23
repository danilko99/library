#ifndef LIBRARYBOOK_H
#define LIBRARYBOOK_H
#include "book.h"

class libraryBook : public book
{

public:

    libraryBook();//конструктор по-умолчанию
    libraryBook(std::string _name, std::string _author, int _year, int _number, int __SerNum, bool __Flag);//конструктор инициализации
    libraryBook(const libraryBook &copyBook);//конструктор копирования
    int getSerNum() const;//далее селекторы и модификаторы
    bool getFlag() const;
    void setSerNum(int _SerNum);
    void setFlag(bool _Flag);
    std::string  allInfo() const;//виртуальный метод (предствление всех полей информации в виде строки)
    int A();//тип элемента (родитель - 0, наследник - 1)
    int SerNum_() const;//перегруженный метод (заменяет селеткор и модификатор для свойства Серийный норме)
    void SerNum_(int _SerNum);
    void setAllInformation(std::string name_,std::string author_,int year_, int sernum_, bool flag_);

    libraryBook operator ++();//постфиксый инкремент (изменение серийного номера)
    libraryBook operator ++(int); //префиксный инкремент
    libraryBook operator --();//постфиксный декремент
    libraryBook operator --(int);//префексный декремент


    friend libraryBook operator + (libraryBook &lb,libraryBook &LB);//дружественные функции перегрузки арифметических операторов
    friend libraryBook operator - (libraryBook &lb,libraryBook &LB);//изменение серийного номера книги
    libraryBook operator *(libraryBook &lb);//перегрузка как медод класса










private:

    int  SerNum;
    bool Flag;


};

#endif // LIBRARYBOOK_H
