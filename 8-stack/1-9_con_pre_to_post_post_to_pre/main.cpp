#include <iostream>
#include <stack>
using namespace std;

/*

bool is_operater(char c) {
    if(c=='/' || c=='+' || c=='*' ||c=='-')
        return true;
        else 
            return false;
}
//from right to left to get the post from pre
string convert_pre_to_post(string & pre) {
    
 stack<string> s;
 for(int i=pre.length()-1; i>=0; i--) {
     if(isalpha(pre[i])) {
         string temp (1,pre[i]);
         s.push(temp);
     }else if(is_operater(pre[i])) {
         string temp1=s.top();
         s.pop();
         string temp2 =s.top();
         s.pop();
         string r = '('+ temp1  + temp2 + pre[i] +')';
         s.push(r);
     }
 }
 string r =s.top();
 s.pop();
 return r;
}
int main(){
     string pre{"*+ab/ef"};
     cout<<convert_pre_to_post(pre)<<endl;
}*/

bool is_operater(char c) {
    if(c=='/' || c=='+' || c=='*' ||c=='-')
        return true;
        else 
            return false;
}

//to get pre go from left to right
string convert_post_to_pre(string & post) {
    stack<string> s;
    for(int i=0 ; i<post.length() ; i++) {
        if(isalpha(post[i])) {
            string temp(1,post[i]);
            s.push(temp);
        }else if(is_operater(post[i])) {
            string temp2=s.top();
            s.pop();
            string temp1=s.top();
            s.pop();
             string r =  post[i] + temp1  + temp2 ;
            s.push(r);
        }
    }
    string r= s.top();
    s.pop();
    return r;
  
}
int main(){
    string post {"ab+ef/* "};
     cout<<convert_post_to_pre(post)<<endl;
}