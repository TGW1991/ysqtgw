#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include"sale_data2.h"
using namespace std;
bool isshort(const sale_data &s1,const sale_data &s2);
int main()
 {
     cout<<"请输入相关信息"<<endl;
     sale_data sale_book;
     vector<sale_data> sale_infor;
     while(read(cin,sale_book))
       {
           sale_infor.emplace_back(sale_book);
       }
     cout<<"排序前输出如下："<<endl;
     for(auto i:sale_infor)
       i.display(cout);
     stable_sort(sale_infor.begin(),sale_infor.end(),isshort);
     cout<<"排序后输出如下："<<endl;    
      for(auto i:sale_infor)
       i.display(cout);
 }
 bool isshort(const sale_data &s1,const sale_data &s2)
   {
       return s1.ISBN().size()<s2.ISBN().size();
   }