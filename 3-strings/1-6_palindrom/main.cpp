#include <iostream>
#include <string>
using namespace std;
#include <deque>
#include <vector>
#include <stack>
#include <queue>

bool is_palindrom(string  s) {
    stack<char> k;
    queue<char> q;
    for(char c : s)  {
        if(isalpha(c)) { 
        k.push(c);
        q.push(c);
    }}
    char c1;
    char c2;
    while(q.size() > 1) {
        c1=k.top();
        c2=q.front();
        k.pop();
        q.pop();
        while(c1 != c2) {
            return false;
        }
    }
    return true;
    
}/*bool is_palindrom(string  s) {
    deque<char> d;
    for(char c : s) 
        d.push_back(c);
    char c1;
    char c2;
    while(d.size() > 1) {
        c1=d.front();
        c2=d.back();
        d.pop_back();
        d.pop_front();
        while(c1 != c2) {
            return false;
        }
    }
    return true;
    
}*/

int main()
{

    cout<<boolalpha;
    vector<string> words={"madam","kaka","ssbss","paap","mama","maam"};
    for(auto s: words) {
        cout<<s<<" : "<<is_palindrom(s)<<endl;
    }
    
}
