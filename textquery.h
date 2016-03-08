#ifndef TEXTQUERY_H
#define TEXTQUERY_H
#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<fstream>
#include<sstream>
#include<set>
using namespace std;
class textquery
   {
	   private:                            //类成员
	           vector<string> line_words;
               map<string,set<int>> data;
       public:                             //构造函数
	           textquery()=default;
			   textquery(ifstream &input);
	   public:
	           bool find(const string &s);
	           void find_print(const string &want_word);
   };
   textquery::textquery(ifstream &input)
     {
          string line;
		  int line_number=0;
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

	 }
   bool textquery::find(const string &s)
     {
         if(data.find(s)==data.end())
			 return false;
	     else
			 return true;
	 }
   void textquery::find_print(const string &want_word)
     {
           cout<<want_word<<" "<<data[want_word].size()<<"times"<<endl;
		   for(auto i=data[want_word].begin();i!=data[want_word].end();++i)
		       {
				  cout<<"(line "<<*i<<") "<<line_words[*i]<<endl;
			    }

	 }
#endif
