#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool is_almost_palindrom (string str, int s , int e) {
    while(s < e) {
         while(!isalnum(str[s]))
             s++;
        while(!isalnum(str[e]))
            e--;
        if(str[s] != str[e])
            return false;
    
     s++;
     e--;
    }
    return true;
}

 bool is_palindrom(string str) {
     int s=0;
     int e= str.length()-1;
     while(s < e) {
          while(!isalnum(str[s]))
             s++;
        while(!isalnum(str[e]))
            e--;
         if(str[s] != str[e]) {
           return   is_almost_palindrom(str , s+1 ,e) || is_almost_palindrom(str , s , e-1);
         }
         s++;
         e--;
     }
     return true;
 }

int main(){
   
	 string array{"abc c dba"};
     
     cout<<is_palindrom(array)<<endl;
}



// check palindrom 
 /*bool is_palindrom(string str) {
     int s=0;
     int e=str.length()-1;
     while(s < e) {
         while(!isalnum(str[s]))
             s++;
        while(!isalnum(str[e]))
            e--;
        if(toupper(str[s]) != toupper(str[e]))
            return false;
        s++;
        e--;
     }
     return true;
 }
 
 
int main()
{ 
     string str ={"A man, a plan, a canal: panama"};
     cout<<is_palindrom(str)<<endl;
}
*/