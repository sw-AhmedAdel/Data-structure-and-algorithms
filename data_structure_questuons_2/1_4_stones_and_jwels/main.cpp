#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
using namespace std;
 // time is log n space is 1

int number_of_Jewels(string j , string s) {
    unordered_set<char> set;
    for(int i=0 ; i<(int)j.size() ; i++)
    {
        if(set.find(j[i])==set.end())
            set.insert(j[i]);
    }
    
    int counter=0;
    for(int i=0 ; i<(int)s.size() ; i++) {
        if(set.find(s[i]) !=set.end())
            counter++;
    }
    return counter;
}
 
int main()
{ 
    string jewels  {"aAc"};
    string stone {"adbcAC"};
    cout<<number_of_Jewels(jewels , stone)<<endl;
}
