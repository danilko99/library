#ifndef BOOK_H
#define BOOK_H
#include <string>
#include <list>

typedef std::string str;//для удобста использования типа std::string

    class book
    {
        private:

            str name;
            str author;
            int year;
            mutable int number;

        public:

            book();//констуктор по умолчанию
            book(str _name, str _author, int _year, int _number);//конструктор инициализации
            book(const book &copyBook);//констуктор копирования
            ~book();//деструктор
            std::string getName() const;//далее селекторы для прайвит свойств
            std::string getAuthor() const;
            int getYear() const;
            int getNumber() const;
            int getNumber_() const;
            int setYear(int _year);//далее модификаторы для прайвит свойств
            void setAuthor(std::string __author);
            void setName(std::string __name);
            void setNumber(int __number);
            virtual std::string allInfo() const;//виртуальный метод (предствление всех полей информации в виде строки)
            virtual void read(std::ifstream File);//чтетие из файла
            virtual int A();//тип элемента (родитель - 0, наследник - 1)            
            virtual void setAllInformation(std::string name_, std::string author_, int year_, int, bool flag_);//витруальный метод (изменяет все свойства класса)

            book operator = (const book &b);// перегрузка оператора присваивания

            bool operator <(const book &b); //операторы сравнения (сравнение года издания)
            bool operator >(const book &b);  //
            bool operator ==(const book &b);  //

            bool operator ||(const book &b);//логические операторы
            bool operator &&(const book &b);

            friend std::ostream& operator<<(std::ostream& buff, const book& b);//перегрузка операторов ввода
            friend std::istream& operator>>(std::istream& buff, book& b);

            book operator()(std::string, std::string,int);//оператор вызова функции (меняет свойства класса)
            template <class T> std::list<T> TempFunc(const T &copyBook1,const T &copyBook2);//шаблонная фун-ция складывает
                                                                        //два объекта произвального класса
                                                                        //довавляя их в std::list


     };


#endif // BOOK_H
