#ifndef MYLIST_H
#define MYLIST_H

#include "book.h"
#include "librarybook.h"
#include <list> //использовался шаблонный класс list
#include <iostream>
#include <fstream>
#include <memory>

class myList : public std::list<std::shared_ptr<book>>
{
    public:
        myList();
        myList(const myList &copyList);
        myList(std::shared_ptr<book> book_);
        std::string getName(int) const;//далее селекторы для прайвит свойств, c выбором эл-та
        std::string getAuthor(int) const;
        int getYear(int) const;
        int getNumber(int) const;
        std::shared_ptr<book> getBook_(int a) const;
        std::string getBook(int) const;
        std::string getAllInfo() const;//представление всего списка в виде строки
        void saveListToFile(char*) const;//сохранение списка в файл
        void readListFromFile(char*);//чтение списка из файла
        int TypeOfElement(int a); //тип элемента (родитель - 0, наследник - 1)
        void setAllInfo(int, std::string name_, std::string author_, int year_, int sernum_, bool flag_);//модификаторы для всех свойств класса
        std::shared_ptr<book> operator[](int a) const; //перегрузка оператора []

        int countOfPrnt();//счетчик колтичества эл-тов (для родителя и наследника)
        int countOfChld();
};

#endif // MYLIST_H
