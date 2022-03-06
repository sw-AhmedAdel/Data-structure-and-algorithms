#include <iostream>
#include <string>
#include <unordered_set>
#include <unordered_map>

#include <vector>
using namespace std;
//time is o(n) space is o(n)

 string find_longest_substr(string str) {
   int longest=0;
   int left=0;
   int right=0;
   unordered_map<char , int> maps;
   vector<int> vec ;
   while(right <(int)str.size()) {
        
       if(maps.find(str[right]) == maps.end()) {
           maps[str[right]] = right;
        }else {
           if(left > maps[str[right]] )
                maps[str[right]]= right;
         else {
           left =maps[str[right]] +1;
           maps[str[right]] = right;
         }
          
       }
       int max= abs(right - left) +1;
       
       if(max > longest) {
           longest = max;
           vec ={left , right+1};
       }
        right++;
   }
   string s = str.substr(vec[0] , vec[1] - vec[0]);
  return s;
}

//time is o*n and space is n why once the loop is broke i will start again it is not cumulative
 /*int find_longest_substr(string str) {
 int max_length=0;
 for(size_t i=0 ; i<str.size() ; i++) {
     unordered_set<char>s;
     int counter=0;
      for(size_t j=i ; j < str.size() ; j++) {
         if(s.find(str[j]) == s.end()) {
             counter++;
             s.insert(str[j]);
         }else {
           break;
         }
     }
       max_length = max(counter , max_length);
 }
 return max_length;
}
*/
int main()
{              // abcdeavac why 6 coz bcdeav v index 6 - b index 1 = 5 + 1  == 6
    string str {"clementisacap"};//abcdeavac//abcdaac //abcbdefake
	cout<<"number of long susbstring is "<<find_longest_substr(str)<<endl;
}
