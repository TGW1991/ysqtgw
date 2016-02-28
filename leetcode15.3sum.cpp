#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
vector<vector<int>> threeSum(vector<int>& nums);
int main()
  {
      vector<int> array={-1,0,1,2,-1,-4};
      auto _answer=threeSum(array);
      cout<<"A solution set is:"<<endl;
      for(auto &i:_answer)
        {   
            cout<<"(";
            for(auto &j:i)
              cout<<j<<",";
            cout<<")";
            cout<<endl;
        }
  }
vector<vector<int>> threeSum(vector<int>& nums) 
    {
        int sub_answer;                //sub_answer==b+c
        vector<int> single_answer;
        vector<vector<int>> answer;
        if(nums.empty()||nums.size()<3)
          return answer={};
        else
        {
                  for(int i=0;i!=nums.size()-2;++i)    
                      {   
                          auto it=find(nums.begin(),nums.begin()+i,nums[i]);
                          if(it!=nums.begin()+i)
                            continue;
                          for(int j=i+2;j!=nums.size();++j)
                            {   
                                auto it=find(nums.begin()+i+2,nums.begin()+j,nums[j]);
                                if(it!=nums.begin()+j)
                                   continue;
                                for(int k=i+1;k!=nums.size();++k)
                                   {
                                       if(k==j)
                                         continue;
                                       else
                                        {
                                           single_answer.clear();
                                           if(nums[i]+nums[k]+nums[j]==0)
                                             {
                                                single_answer.push_back(nums[i]);
                                                single_answer.push_back(nums[j]);
                                                single_answer.push_back(nums[k]);
                                                sort(single_answer.begin(),single_answer.end());
                                                answer.push_back(single_answer);
                                             } 
                                        } 
                                   }
                            }
                      }
         }      
        sort(answer.begin(),answer.end());
        auto it=unique(answer.begin(),answer.end());
        answer.erase(it,answer.end());
        return answer;
     }