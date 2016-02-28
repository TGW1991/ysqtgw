#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
static int bull=0,cow=0;
string getHint(string _secret, string _guess);
int main()
  {
      cout<<"请出题者写下您的密码"<<endl;
      string secret;
      cin>>secret;
      string right_answer;
      right_answer.append(to_string(secret.size()));
      right_answer.append("A");
      right_answer.append(to_string(0));
      right_answer.append("B");              //判定getHint函数返回值正确与否的字符串
      cout<<"请选手写下您的答案"<<endl;
      string player_answer;
      while(cin>>player_answer)
        {
            auto my_guess=getHint(secret,player_answer);
            cout<<bull<<" "<<"bull"<<" "<<"and"<<" "<<cow<<" "<<"cow"<<endl;
            if(my_guess==right_answer)
              break;
            else
              cout<<"请选手再次写下答案"<<endl;
        }
      cout<<"Congratulations buddy"<<endl;
  }
string getHint(string _secret, string _guess)
  {   bull=0;
      cow=0;
      string s;
      for(auto i=0;i!=_guess.size();++i)
        {
            if(_guess[i]==_secret[i])
                    {
                        ++bull;
                        _secret[i]=' ';
                        _guess[i]='/';           //在secret中找到的字符设置成空格防止guess中的重复字符
                    }
        }
      for(auto i=0;i!=_guess.size();++i)
        {
            for(auto j=0;j!=_secret.size();++j)
              {
                  if(_guess[i]==_secret[j])
                    {
                        ++cow;
                        _secret[j]=' ';
                        _guess[i]='/';
                        break;
                    }
              }
        }    
      s.append(to_string(bull));
      s.append("A");
      s.append(to_string(cow));
      s.append("B");
      return s;
  } 