#include "book.h"
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>


 book::book() //конструктор по умолчанию
    {
        name="";
        author="";
        year=0;
        number=0;

    }

 book::book(std::string _name, std::string _author, int _year, int _number)// конструктор инициализации
    {
        name=_name;
        author=_author;
        year=_year;
        number=_number;
    }

 book::book(const book &copyBook)// конструктор копирования
    {
        name=copyBook.name;
        author=copyBook.author;
        year=copyBook.year;
        number=copyBook.number;
    }



 book::~book()//деструктор
    {
    }

 std::string book::getName() const //далее селекторы для private свойств (название, автор, год издания)
    {
        return name;
    }

 std::string book::getAuthor() const
    {
        return author;
    }

 int book::getNumber() const
    {
        return number;
    }

 int book::getNumber_() const//mutable свойство
    {
        return number++;
    }

 int book::getYear() const
    {
        return year;
    }

 int book::setYear(int _year)//модификаторы для прайвит свойств (для года издания - с проверкой на корректность ввода)
    {
     if ((_year<1900)||(_year>2016)) return 0;
     else
      year=_year;
      return 1;
    }

 void book::setAuthor(std::string __author)
    {
        author=__author;
    }


 void book::setName(std::string __name)
    {
        name=__name;
    }

 void book::setNumber(int __number)
    {
        number=__number;
    }

 std::string  book::allInfo() const
 {
     std::string Year = std::to_string(year);
     std::string a = name+" "+author+" " + Year;
     return a;
 }


 void book::read(std::ifstream File)
 {

     File >> name >> author >> year;

 }

 int book::A()
 {
     return 0;
 }



 void book::setAllInformation(std::string name_, std::string author_, int year_, int sernum_, bool flag_)
 {
     setName(name_);
     setAuthor(author_);
     setYear(year_);
 } 



 book book::operator = (const book &b)// перегрузка оператора присваивания
 {
     name=b.name;
     author=b.author;
     year=b.year;
     number=b.number;
     return *this;
 }


 bool book::operator <(const book &b)//операторы сравнения (сравнение года издания)
 {
     if (year < b.year)
         return true;
     else return false;
 }

 bool book::operator >(const book &b)
{
    if (year > b.year)
        return true;
    else return false;
}

 bool book::operator ==(const book &b)
 {
     if (year == b.year)
         return true;
     else return false;
 }

 bool book::operator ||(const book &b)//логический оператор
 {
     if (year || b.year)
         return true;
     else return false;
 }

 bool book::operator &&(const book &b)
 {
     if (year && b.year)
         return true;
     else return false;
 }

 std::ostream& operator<<(std::ostream& buff, const book& b)
 {
     buff << b.allInfo();
     return buff;
 }

 std::istream& operator>>(std::istream& buff, book& b)
 {
     buff >> b.name;
     buff >> b.author;
     buff >> b.year;
     return buff;
 }

book book::operator()(std::string _nm, std::string _athr, int _yr)
  {
   name=_nm;
   author= _athr;
   year = _yr;
   return *this;
  }

template <class T>
std::list<T> book::TempFunc(const T &copyBook1,const T &copyBook2)// шаблонная фун-ция
    {
        std::list<T> Inc;
        Inc.push_back(copyBook1);
        Inc.push_back(copyBook2);
    }
