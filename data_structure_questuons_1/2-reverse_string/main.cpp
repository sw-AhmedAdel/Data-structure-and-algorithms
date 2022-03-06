#include <iostream>
#include <string>
using namespace std;
#include <vector>
#include <stack>
//time o(n) space o(n)
/*
void reverse_string (vector<char> & chars) {
    stack<char> s;
    for(int i=0 ; i<chars.size() ; i++) {
        s.push(chars[i]);
    }
    int i=0;
    while(!s.empty()) {
        chars[i++]=s.top();
        s.pop();
    }
}*/
//time o(n) space o(1)

void reverse_string (vector<char> & chars) {
   int s=0;
   int e=chars.size()-1;
   while(s < e) {
       swap(chars[s] , chars[e]);
       s++ ;
       e--;
   }
}
int main()
{
	 vector<char> chars ={'h','e','l','l','o'};
     reverse_string(chars);
     for(char s : chars)
         cout<<s<<"";
    cout<<endl;
}
