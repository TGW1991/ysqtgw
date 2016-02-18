#include<iostream>
#include<string>
#include"interestRate.h"
using namespace std;
double interestrate::int_rate;
int main()
  {   
      double r;
      cout<<"输入利率"<<endl;
      interestrate my_account1;
      interestrate my_account2;
      while(cin>>r)
          {  
             my_account1.rate(r);
            interestrate my_account1("haskdj",35);
            interestrate my_account2("hasfds",12);
             my_account1.display(cout);
             my_account2.display(cout);
             cout<<"输入利率"<<endl;
          }
             
     
        
  }