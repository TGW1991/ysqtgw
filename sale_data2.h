#ifndef SALE_DATA_H
#define SALE_DATA_H
#include<iostream>
#include<vector>
#include<string>
using namespace std;
class sale_data
      {
          private:
                  string bookno;
                  string author;
                  double price;
          public:                               //成员函数
                  const string& ISBN() const {return bookno;}
                  sale_data& display(ostream& out){do_display(out);return *this;}
          public:                              //构造函数
                  sale_data()=default;          
                  sale_data(istream& is);
          public:                              //友元函数
                  friend istream& read(istream& is,sale_data& s);
          private:
                  void do_display(ostream& os){os<<bookno<<"  "<<author<<"  "<<price<<endl;}
      };
  sale_data::sale_data(istream& is)
      {
          read(is,*this);
      }
  istream& read(istream& is,sale_data& s)
      {
          is>>s.bookno>>s.author>>s.price;
          return is;
      }
#endif