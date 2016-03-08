#include<iostream>
#include<vector>
#include<fstream>
#include<sstream>
#include<map>
#include<set>
using namespace std;
int main()
 {
	 ifstream input("/home/ysq/桌面/bb.txt");
	 string line;
     int line_number=0;
	 vector<string> line_words;
	 map<string,set<int>> data;
	 while(getline(input,line))
	   {
		   line_words.push_back(line);
		   istringstream record(line);
		   string word;
		   while(record>>word)
		     {
			    data[word].insert(line_number);	 
			 }
		   ++line_number;
	   }
	 cout<<"请输入您想查找的单词"<<endl;
	 string want_word;
	 while(cin>>want_word)
	   {   cout<<want_word<<" "<<data[want_word].size()<<"times"<<endl;
		   for(auto i=data[want_word].begin();i!=data[want_word].end();++i)
		      {
                 cout<<"(line "<<*i<<") "<<line_words[*i]<<endl;
			  }
	   }
 }
