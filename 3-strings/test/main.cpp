#include <iostream>
#include <string>
#include <vector>
using namespace std;
 
    
bool is_angram(string s1 , string s2) {
 vector<int> hash1 (26 ,0);
 vector<int> hash2(26 , 0);
 int size1 = s1.size();
 int size2 =s2.size();
 int right=0;
 int left=0;
 while(right < size1) {
     hash1[s1[right] - 97] ++;
     hash2[s2[right]- 97]++;
     right++;
 }
 
 
 while ( right < size2) {
     if(hash1 == hash2)
         return true;
         else {
             
          
             hash2[s2[right] - 97] ++;
             hash2[s2[left]- 97] --;
             left ++;
              right ++;
         }
 }
 return false;
 
}

int main(){
    string s1="cab";
    string s2="dbabcd";
    if(is_angram(s1, s2)) 
        cout<<"in angram"<<endl;
        else 
            cout<<"not angram"<<endl;
            
          /*   string s1="ab";
             string s2="cababcc";*/
            
            
}

