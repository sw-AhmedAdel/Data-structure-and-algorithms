#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//البريفكس عشان يتحول لازم الاول اقلب النفيكس بعدها اطبق القواعد
//هى هى نفس القواعد ما عدا لو + واللى بعدها + يبقى احطها عادى جدا طلاما اللى هيدخل والىى على توب الاستكات نفس الهيمنة
//يبقى اضفها عليها وبس
//ولازم الانفكس اعكس كل اللى فية وبعدها اعكس الاقواس ولما احولة لى برفيكس لازم اعكسة تانى بس من غير الاقواس
class stack {
    char *arr;
    int n;
    int p=-1;
public:
   stack(int s) : n{s} {
       arr=new char[n];
   }
    void push(char c) {
        p++;
        arr[p]=c;
    }
    void pop() {
        p--;
    }
    char top(){
        return arr[p];
    }
    
    bool empty() {
        if(p==-1)
            return true;
            else 
                return false;
    }
    
};

bool is_operater (char c) {
    if(c=='/' || c=='*' ||c=='-' ||c=='+' ||c=='^')
        return true;
        else 
            return false;
}
int precedence (char c) {
    if(c=='^')
        return 3;
        else if(c=='/' || c=='*')
            return 2;
            else if(c=='+' || c=='-')
                return 1;
                else 
                    return 0;
}

 string reverses(stack & s , string &infix) {
     for(int i=0 ; i<infix.length() ;i++) {
         s.push(infix[i]);
     }
     infix.clear();
     while(!s.empty()) {
         infix+=s.top();
         s.pop();
     }
     for(int i=0 ; i<infix.length() ;i++) {
         if(infix[i] =='(')
             infix[i]=')';
             else if(infix[i]==')')
                 infix[i]='(';
                 else 
                     continue;
     }
     return infix;
 }

string get_prefixe(stack & s , string &infix) {
    string prefix;
 for(int i=0 ; i<infix.length() ; i++) {
          if(infix[i]==' ')
              continue;
          else if(isalpha(infix[i]) || isdigit(infix[i])  ) 
                 prefix+=infix[i];
            else if(infix[i]=='(')
                s.push(infix[i]);
            else if(infix[i]==')') {
                while(!s.empty() && s.top() !='(') {
                    prefix+=s.top();
                    s.pop();
                }
                s.pop();
            }
                    else if(is_operater(infix[i])) {
                    if(s.empty())
                       s.push(infix[i]); 
                       
                    else { 
                        if(precedence(infix[i] >= precedence(s.top())) )
                            s.push(infix[i]);
                            else  {
                                while(!s.empty() && precedence(infix[i]) < precedence(s.top())) {
                                    
                                    prefix+=s.top();
                                    s.pop();
                                }
                                s.push(infix[i]);
                            }
                    }
                
                   }
                    
                }
                while(!s.empty()) {
                    prefix+=s.top();
                    s.pop();
                }
                
     reverse(prefix.begin() , prefix.end());
     return prefix;
}
 

int main()
{
    string infix = ("k+l-m*n+(o^p)*w/u/v/*t+Q");
    cout<<"infix is "<<infix<<endl;
    stack r(infix.length());
    infix = reverses(r , infix);
    stack s(infix.length());
   	string prefixe = get_prefixe(s, infix);
  	cout<<endl<<"prefix EXPRESSION: "<<prefixe<<endl;
	  
}
