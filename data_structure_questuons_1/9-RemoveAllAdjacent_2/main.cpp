#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <unordered_map>
using namespace std;
//time is o(n)
//space o(n)

class level {
public:
    char c;
    int count;
};
string remove_dublicates(string strings , int k) {
      stack<level> s;
      string temp;
      for(int i=0 ; i<strings.size() ; i++) {
          if(s.empty()) {
 
              s.push(level{ strings[i], 1});
          }
          else {
              if(s.top().c != strings[i]) {
              s.push(level{ strings[i], 1});
              }
              else {
                  if(s.top().c == strings[i]) {
                      s.top().count++;
                  }
                  if(s.top().count == k)
                      s.pop();
              }
          }
      }
      while(!s.empty()) {
          while(s.top().count != 0) {
              temp+=s.top().c;
              s.top().count--;
          }
          s.pop();
      }
      reverse(temp.begin() , temp.end());
      //why coz i am using stak so it is reverse the string so use reverse to get the string like it was
      return temp;
}
 

int main()
{
	 string strings {"deeedbbcccbdaa" };
     cout<<remove_dublicates(strings , 3)<<endl;
}
