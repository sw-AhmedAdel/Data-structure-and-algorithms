#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool check_angrams(vector<char>  a , vector <char> b) {
    unordered_map<char , int> maps;
    for(int i= 0 ; i<a.size() ; i++) {
        if(maps.find(a[i] )== maps.end())
            maps[a[i]]=0;
        maps[a[i]]++;
    }
    for(int i=0 ;i < b.size() ; i++) {
        if(maps.find(b[i]) ==maps.end() || maps[b[i]] == 0)
            return false;
            else 
                maps[b[i]]--;
    }
    return true;
    
}

int main()
{
	 vector<char>  a {'d', 'e', 'c' ,'i' ,'m', 'a' ,'l' };
     vector <char> b{'e', 'd', 'i' ,'c' ,'a', 'm' ,'l'} ;
     if(check_angrams(a , b))
         cout<<"True"<<endl;
         else 
             cout<<"false"<<endl;
     
    
}
