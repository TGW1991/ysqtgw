#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include"sale_item.h"
using namespace std;
void print_all(vector<sale_item> s);
void add_item(vector<sale_item> &s);
void delete_item(vector<sale_item> &s);
void change_item(vector<sale_item> &s);
int main()
  {   cout<<"请输入基准利率"<<endl;
      rate(cin);
      vector<sale_item> mybook;
      sale_item s;
      ifstream in("/home/ysq/桌面/book_system.txt");
      ofstream out("/home/ysq/桌面/book_system1.txt");
      while(read(in,s))
        {
            mybook.push_back(s);
        }
      char ch;
      cout<<"请输入您选择的功能"<<endl;
      cout<<"a.打印所有的书籍记录"<<"    "<<"b.添加一条记录\n"
          <<"c.删除一条记录"<<"      "<<"d.修改一条信息\n"<<"q.退出"<<endl;
      while(cin>>ch)  
        {
            switch(ch)
              {
                  case 'a':print_all(mybook);break;
                  case 'b':add_item(mybook);break;
                  case 'c':delete_item(mybook);break;
                  case 'd':change_item(mybook);break;
                  case 'q':break;
              }
            if(ch=='q')
              break;
            cout<<"请输入您选择的功能"<<endl;
            cout<<"a.打印所有的书籍记录"<<"    "<<"b.添加一条记录\n"
                <<"c.删除一条记录"<<"      "<<"d.修改一条信息\n"<<"q.退出"<<endl;
        }   
       cout<<"拜拜傻逼"<<endl;
       for(auto i:mybook)
         print(out,i);
       in.close();
       out.close();
  }
 void print_all(vector<sale_item> s)
   {
       for(auto i:s)
         {
             i.display(cout);
             cout<<"\n";
         }
   } 
  void add_item(vector<sale_item> &s)
   {
       cout<<"请输入书籍的所有信息"<<endl;
       sale_item s1;
       read_cin(cin,s1);
       int j=0;
       for(auto &i:s)
        {
            if(compare_ISBN(i,s1))
              {
                  add(i,s1);
                  j=1;
                  break;
              }
        }
        if(!j)
         {
             s.push_back(s1);
         }
   }
  void delete_item(vector<sale_item> &s)
    {
        cout<<"请输入你想删除的书目号（q退出）"<<endl;
        string s1;
        int j=0;
        char ch;
        while(cin>>s1&&s1!="q")
        {
            for(auto i=s.begin();i!=s.end();i++)
               {
                   if((*i).ISBN()==s1)
                      {
                         s.erase(i);
                         j=1;
                         break;
                      }
                   else
                      continue;
                }
             if(!j)
               cout<<"没有找到该书目请重新输入（q退出）"<<endl;
             else
               cout<<"请继续输入（q退出）"<<endl;
        }
    }
   void change_item(vector<sale_item> &s)
    {
        cout<<"请输入您要改变书本的ISBN号"<<endl;
        string s1;
        int j=0;
        while(cin>>s1&&s1!="q")
        {   cout<<"进入循环"<<endl;
            for(auto i=s.begin();i!=s.end();++i)
               {
                   if((*i).ISBN()==s1)
                      {
                         cout<<"请输入您要改变的项目"<<endl;
                         string s2;
                         while(cin>>s2&&s2!="q")
                           {
                               if(s2=="bookNO")
                                 {
                                    cout<<"请输入您要改变成什么"<<endl;
                                    string s3;
                                    cin>>s3;
                                    (*i).set_bookNO(s3);
                                    cout<<"请继续输入（q退出）"<<endl;
                                 }
                                else if(s2=="author")
                                 {
                                    cout<<"请输入您要改变成什么"<<endl;
                                    string s3;
                                    cin>>s3;
                                    (*i).set_author(s3);
                                    cout<<"请继续输入（q退出）"<<endl;
                                 }
                                else if(s2=="price")
                                 {
                                    cout<<"请输入您要改变成什么"<<endl;
                                    double s3;
                                    cin>>s3;
                                    (*i).set_price(s3);
                                    cout<<"请继续输入（q退出）"<<endl;
                                 }
                                else if(s2=="sales_volume")
                                 {
                                    cout<<"请输入您要改变成什么"<<endl;
                                    int s3;
                                    cin>>s3;
                                    (*i).set_sales_volume(s3);
                                    cout<<"请继续输入（q退出）"<<endl;
                                 }
                                else
                                  cout<<"没找到您要修改的项目,请重新输入（q退出）"<<endl;
                           }
                         j=1;
                         break;
                      }
                }
             if(!j)
               cout<<"没有找到该书目请重新输入（q退出）"<<endl;
             else
               cout<<"请继续输入（q退出）"<<endl;
        }
        
    }