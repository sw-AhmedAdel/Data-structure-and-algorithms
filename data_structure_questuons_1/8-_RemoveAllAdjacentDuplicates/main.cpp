#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <unordered_map>
using namespace std;
//time is o(n)
//space o(n)
/*
string remove_dublicates(string s) {
      string temp;
      unordered_map<char , int> maps;
      for(int i=0 ; i < s.size() ; i++) {
          if(maps.find(s[i] )== maps.end())
              maps[s[i]]=0;
          maps[s[i]]++;
      }
      
      auto it= maps.begin();
      while(it != maps.end()) {
         if(it->second % 2 != 0) {
             temp.push_back(it->first);
         }
         it++;
      }
      return temp;
}
*//*
string remove_dublicates(string strings) {
      string temp;
      stack<char> s;
      for(int i=0 ; i<strings.size() ; i++) {
          if(s.empty()) {
              s.push(strings[i]);
          }
          else {
           if(strings[i]!= s.top()) {
              s.push(strings[i]);
          }
          else 
              s.pop();
         }
      }
      if(s.empty())
          return " ";
      while(!s.empty()) {
          temp+=s.top();
          s.pop();
      }
      reverse(temp.begin() , temp.end());
      return temp;
}*/

//this is the most optimal solution 
// time o(n) , space o(1) // here try to simulate the stack
string remove_dublicates(string strings) {
     string temp;
     int top=-1;
     for(int i=0 ; i<strings.size() ; i++) {
         if(top == -1) {
             top++;
             strings[top] = strings[i];
         }
         else {
             if(strings[top] != strings[i]) {
                 top++;
                 strings[top] = strings[i];
             }
             else 
                 top--;
         }
     }
     for(int i=0 ; i<= top; i++)
         temp+=strings[i];
     return temp;
}

int main()
{
	 string strings {"abbaca"};
     cout<<remove_dublicates(strings)<<endl;
}
