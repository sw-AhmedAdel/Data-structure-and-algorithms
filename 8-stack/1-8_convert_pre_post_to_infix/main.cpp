#include <iostream>
#include <stack>
using namespace std;

/*
// scan from left to right
bool is_operater(char c) {
    if(c=='/' || c=='+' || c=='*' ||c=='-')
        return true;
        else 
            return false;
}

string convert(string & post) {
     stack<string> s;
     for(int i=0 ; i<post.length() ; i++) {
         if(isalpha(post[i]))
         {
             string temp (1, post[i]);
             s.push(temp);
         }else if(is_operater(post[i])) {
             string temp2=s.top();
             s.pop();
             string temp1=s.top();
             s.pop();
             string r = '(' + temp1 + post[i] + temp2 +')';
             s.push(r);
         }
     }
     string r=s.top();
     s.pop();
     return r;
}

int main()
{
	 
     string post {"ab+ef/*"};
     cout<<convert(post)<<endl;
}
*/

bool is_operater(char c) {
    if(c=='/' || c=='+' || c=='*' ||c=='-')
        return true;
        else 
            return false;
}

// from right to left
string convert(string & pre) {
   stack<string> s;
   for(int i=pre.length(); i>=0 ; i--) {
       if(isalpha(pre[i])) {
           string temp (1,pre[i]);
           // temp.push_back( pre[i] ); 
           s.push(temp);
       }else if(is_operater(pre[i])) {
           string temp1= s.top();
           s.pop();
           string temp2=s.top();
           s.pop();
           string r='(' + temp1 + pre[i] + temp2 + ')';
           s.push(r);
       }else 
           continue;
   } 
   string r= s.top();
   s.pop();
   return r;
}
int main(){
     string pre{"*+ab/ef"};
     cout<<convert(pre)<<endl;
}