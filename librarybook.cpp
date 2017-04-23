#include "librarybook.h"
#include "book.h"

#include <sstream> //для конвертирования числа из int в string


libraryBook::libraryBook() : book::book()//конструктор по-умолчанию
{
    SerNum = 0;
    Flag = false;
}


libraryBook::libraryBook(std::string _name, std::string _author, int _year, int _number,int __SerNum, bool __Flag ) : book::book(_name, _author, _year,_number)//конструктор инициализации
{
    SerNum=__SerNum;
    Flag=__Flag;

}

libraryBook::libraryBook(const libraryBook &copyBook) : book::book(copyBook)//констуктор копирования
{
    SerNum=copyBook.SerNum;
    Flag=copyBook.Flag;
}

int libraryBook::getSerNum() const //далее селекторы  и модификаторы
{
    return SerNum;
}

bool libraryBook::getFlag() const
{
    return Flag;
}

void libraryBook::setSerNum(int _SerNum)
{
   SerNum=_SerNum;
}

void libraryBook::setFlag(bool _Flag)
{
   Flag=_Flag;
}

std::string libraryBook::allInfo() const//предствление всей информации о книге в виде строки
{
    std::string a = book::allInfo();
    std::string serNum = std::to_string(SerNum);
    a += " " + serNum;
    if (Flag==false) a+=" 0";
    else a+=" 1";
    return a;
}

int libraryBook::A()
{
    return 1;
}


int libraryBook::SerNum_() const
{
    return SerNum;
}

void libraryBook::SerNum_(int _SerNum)
{
    SerNum = _SerNum;
}

void libraryBook::setAllInformation(std::string name_,std::string author_,int year_, int sernum_, bool flag_)
{
    setName(name_);
    setAuthor(author_);
    setYear(year_);
    setSerNum(sernum_);
    setFlag(flag_);
}



libraryBook libraryBook::operator ++()
{
    SerNum++;
    return *this;
}

libraryBook libraryBook::operator ++(int)
{
    libraryBook b(*this);
    SerNum++;
    return b;
}

libraryBook libraryBook::operator --()
{
    SerNum--;
    return *this;
}

libraryBook libraryBook::operator --(int)
{
    libraryBook b(*this);
    SerNum--;
    return b;
}

libraryBook operator + (libraryBook &lb, libraryBook &LB)
{
    LB.SerNum+=lb.SerNum;
    return LB;
}

libraryBook operator - (libraryBook &lb, libraryBook &LB)
{
    LB.SerNum-=lb.SerNum;
    return LB;
}

libraryBook libraryBook::operator * (libraryBook &lb)
{
    SerNum==SerNum*lb.SerNum;
    return *this;
}

