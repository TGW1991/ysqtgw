#ifndef SALE_ITEM_H
#define SALE_ITEM_H
using namespace std;
class sale_item
    {
        private:                 //类中对象成员
                string bookNO;
                string author;
                double price;
                int sales_volume;
                double total_value;
                double price_US;
                static double interestrate;
                void do_display(ostream &is);
        public:                             //构造函数（在类外定义时必须作用域运算符或者inline）
               sale_item(string s,string a,double p,int s_v):bookNO(s),author(a),price(p),sales_volume(s_v),total_value(p*s_v),price_US(p*interestrate){}
               sale_item()=default;
               sale_item(ifstream &is);
               sale_item(istream &is);
        public:                              //成员函数（在类外定义时必须作用域运算符或者inline）
               string ISBN() const {return bookNO;}
               string AUTHOR() const {return author;}
               sale_item& combine(const sale_item& ptr);
               sale_item& display(ostream &s){do_display(s);return *this;}
               sale_item& set_bookNO(const string s1){bookNO=s1;return *this;}
               sale_item& set_author(const string s1){author=s1;return *this;}
               sale_item& set_price(const double i){price=i;return *this;}
               sale_item& set_sales_volume(const int i){sales_volume=i;return *this;}
        public:                               //友元函数（在类外定义无需作用域运算符，外部代码中调用是也不用作用域运算符，可以访问私有函数）
               friend ofstream& print(ofstream& out,const sale_item& item);
               friend ifstream& read(ifstream& is,sale_item& item);
               friend istream& read_cin(istream& is,sale_item& item);
               friend sale_item& add(const sale_item &s1,const sale_item &s2); 
               friend bool compare_ISBN(const sale_item &s1,const sale_item &s2);
               friend void rate(istream &s);                                
    };
    static double interestrate;
    inline sale_item& sale_item::combine(const sale_item& ptr)
      {                                                                                                     
          price+=ptr.price;
          sales_volume+=ptr.sales_volume;
          total_value+=ptr.total_value;
          price_US+=ptr.price_US;
          return *this;
      }
    sale_item::sale_item(ifstream &is)
      {
          read(is,*this);      
      }
    sale_item::sale_item(istream &is)
      {
          read_cin(is,*this);
      }
    ifstream& read(ifstream& is,sale_item& item)
      {
          is>>item.bookNO>>item.author>>item.price>>item.sales_volume;
          item.total_value=item.price*item.sales_volume;
          item.price_US=item.price*interestrate;
          return is;
      }
    istream& read_cin(istream& is,sale_item& item)
      {
          is>>item.bookNO>>item.author>>item.price>>item.sales_volume;
          item.total_value=item.price*item.sales_volume;
          item.price_US=item.price*interestrate;
          return is;
      }
    ofstream& print(ofstream& out,const sale_item& item)
      {
          out<<item.bookNO<<"     "<<item.author<<"      "<<item.price<<"       "<<item.sales_volume<<"       "<<item.total_value<<"       "<<item.price_US;
          return out;
      }
    sale_item& add(sale_item &s1,sale_item &s2)
      {
          s1.combine(s2);
          return s1;
      }
    bool compare_ISBN(const sale_item &s1,const sale_item &s2)
      {
          if(s1.ISBN()==s2.ISBN())
            return 1;
          else 
            return 0;
      }
    void sale_item::do_display(ostream &is)
      {
          is<<bookNO<<"     "<<author<<"      "<<price<<"       "<<sales_volume<<"       "<<total_value<<"       "<<price_US;
      } 
    void rate(istream &s)
      {
          s>>interestrate;
      }
#endif