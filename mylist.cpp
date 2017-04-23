#include <iostream>
#include "mylist.h"
#include <string>
#include <list>

myList::myList() : std::list<std::shared_ptr<book> >()
{

}

myList::myList(const myList &copyList) : std::list<std::shared_ptr<book> >(copyList.begin(), copyList.end())
{

}

myList::myList(std::shared_ptr<book> book_)
{
    push_back(book_);

}



void myList::setAllInfo(int a,std::string name_,std::string author_,int year_, int sernum_, bool flag_)
    {
        const_iterator p = begin( );
       for (int i = 0; i < a; ++i, ++p);
       (*p)->setAllInformation(name_,author_,year_,sernum_,flag_);
    }

std::string myList::getName(int a) const//далее селекторы для private свойств (название, автор, год издания)
   {
       const_iterator p = begin( );
       for (int i = 0; i < a; ++i, ++p);
       return (*p)->getName();
   }

std::string myList::getAuthor(int a) const
   {
        const_iterator p = begin( );
        for (int i = 0; i < a; ++i, ++p);
        return (*p)->getName();
   }


int myList::getYear(int a) const
   {
        const_iterator p = begin( );
        for (int i = 0; i < a; ++i, ++p);
        return (*p)->getYear();
   }

int myList::getNumber(int a) const
   {
        const_iterator p = begin( );
        for (int i = 0; i < a; ++i, ++p);
        return (*p)->getNumber();
   }


std::string myList::getBook(int a) const
{
    const_iterator p = begin( );
    for (int i = 0; i < a; ++i, ++p);
    return (*p)->allInfo();
}


std::shared_ptr<book> myList::getBook_(int a) const
{
    const_iterator p = begin( );
    for (int i = 0; i < a; ++i, ++p);
    return (*p);
}



std::string myList::getAllInfo() const
   {
        std::string A;
        const_iterator p = begin( );
        for (int i = 0; i < size(); ++i, ++p) A+=(*p)->allInfo()+"\n";
        return A;
   }


void myList::saveListToFile(char *NameOfFile) const
{
    std::ofstream File;
    File.open(NameOfFile); // связываем объект с файлом
    File << getAllInfo(); // запись листа в Файл
    File.close(); // закрываем файл
}

void myList::readListFromFile(char *NameOfFile)
{

    std::ifstream File;

    std::string buff;
    int n = 0, i, type;

    File.open(NameOfFile);
    while (getline(File,buff)) n++;

    File.close();
    File.open(NameOfFile);


    for (i=0; i<n; i++)
    {
        std::shared_ptr<book> bk = std::make_shared<book>( );
        std::shared_ptr<libraryBook> lbk = std::make_shared<libraryBook>( );

        File >> type;
        std::string name;
        File >> name;
        std::string author;
        File >> author;
        int year;
        File >> year;
        switch (type)
        {
        case 0:
            bk->setName(name);
            bk->setAuthor(author);
            bk->setYear(year);

            push_back(bk);

            break;
        case 1:
            int sernum;
            File >> sernum;
            bool flag;
            File >> flag;

            lbk->setName(name);
            lbk->setAuthor(author);
            lbk->setYear(year);
            lbk->setSerNum(sernum);
            lbk->setFlag(flag);

            push_back(lbk);

            break;
         }
    }
    File.close();

}


int myList::TypeOfElement(int a)
{
    int buff;
    iterator p = begin( );
    for (int i = 0; i < a; ++i, ++p);
    buff = (*p)->A();
    return buff;
}


std::shared_ptr<book> myList::operator [](int a) const
{
    const_iterator p = begin( );
    for (int i = 0; i < a; ++i, ++p);
    return (*p);
}



int myList::countOfPrnt()
{
    int count = 0;
    iterator p = begin();
    for (int i = 0; i < size(); ++i, ++p)
    if (TypeOfElement(i)==0) count++;
    return count;
}

int myList::countOfChld()
{
    return (size()-countOfPrnt());
}
