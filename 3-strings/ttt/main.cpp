#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
bool check( unordered_map<char , int> &map_1 ,  unordered_map<char , int>& map_2 , string & s1) {
        for(int i=0 ; i < map_1.size() ; i++) {
            if(map_1.find(s1[i]) == map_1.end() || map_2.find(s1[i]) == map_2.end())
                return false;
        }
        return true;
    }
bool is_angram(string s1 , string s2) {
 
    unordered_map<char , int> map_1 ;
    unordered_map<char , int> map_2;
    int size_1 = s1.size();
    int size_2 = s2.size();
    int right =0;
    int left =0;
    while( right < size_1) {
         if(map_1.find(s1[right]) == map_1.end() )
              map_1[s1[right]]=0; 
        map_1[s1[right]]++;
        
         if(map_2.find(s2[right]) == map_2.end() )
              map_2[s2[right]]=0; 
        map_2[s2[right]]++;
        right ++;
    }
    right--;
    while(right < size_2) {
       if(check(map_1 , map_2 , s1))
           return true;
            else {
                right++;
        if(map_2.find(s2[right]) == map_2.end() )
              map_2[s2[right]]=0; 
        map_2[s2[right]]++;
           
            if(map_2[s2[left]] == 1)
             map_2.erase(s2[left]);
            }
            map_2[s2[left]] --;
            left++;
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

