#ifndef SALE_DATA_H
#define SALE_DATA_H
using namespace std;
class sale_data
    {   
        
        private:
                 string BOOKNO;
                 double price;
                 int count;
                 double total_value;
        public:
                 sale_data(string s,double p,int c):BOOKNO(s),price(p),count(c),total_value(p*c) {}
                 sale_data():sale_data("",0,0) {cout<<"执行委托的默认函数"<<endl;}
                 sale_data(string s):sale_data(s,0,0) {cout<<"执行只输入书号的委托构造函数"<<endl;}
                 sale_data(istream &s):sale_data(){read(s,*this);}
                 friend std::istream &read(std::istream &is,sale_data &item);
                 
              
    };
     inline istream& read(istream &is,sale_data &item)
        {
            cout<<"执行输入委托函数"<<endl;
            is>>item.BOOKNO>>item.price>>item.count>>item.total_value;
            item.total_value=item.price*item.count;
            return is;
        }
#endif