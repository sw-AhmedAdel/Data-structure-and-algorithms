#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;
 
  void push_to_vec(string str , int s , int e , vector<string> & vec) {
     string temp;
     while(s < e) {
         temp+=str[s];
         s++;
     }
     //temp=str.substr(s , e-s);
     vec.push_back(temp);
 }
 
 vector<string> get_vec_fron_str (string str ) {
     vector<string>  vec ;
     int s=0;
     while(s < (int)str.size()) {
         int e = s;
         if(str[s] ==' ')
             s++;
         else if(str[s] !=' ' && str[e] !=' ' ) {
             while(e < (int)str.size() && str[e] !=' ')
                 e++;
          push_to_vec(str , s ,e , vec);
          s= e+1;
         }  
     }
     return vec;
 }

 int main() {//    0123456789
     string str ={"will will be a great a javascript devolper javascript "};
     vector<string >vec = get_vec_fron_str(str);
     for(auto v : vec)  
       cout<<v<<" ";
    cout<<endl;  
 }