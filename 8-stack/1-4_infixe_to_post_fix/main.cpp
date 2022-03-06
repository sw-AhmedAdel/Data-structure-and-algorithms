#include <iostream>
#include <string>
#include <cstring>
using namespace std;

class stack {
    int top=-1;
    char *arr;
    int n;
public:
    stack(int s) : n{s} {
        arr=new char[n];
    }
    void push(char c) {
        if(top== n-1)
            cout<<"stack is full"<<endl;
            else {
                top++;
                arr[top]=c;
            }
    }
    void pop(){
     top--;
    }
    
    char top_fun() {
        if(top == -1)
            return '0';
            else 
                return arr[top];
    }
    bool is_empty() {
        if(top==-1)
            return true;
            else 
                return false;
    }
    void display(){
        for(int i=top ; i>=0 ; i--)
            cout<<arr[i]<<endl;
    }
    
    bool is_operater(char c) {
        if(c=='/' || c=='-' || c=='*' || c=='+')
            return true;
            else 
                return false;
    }
    int precedence(int s) {
        if(s =='-' || s=='+')
            return 1 ;
            else if(s=='*' || s=='/')
                return 2;
                else 
                    return 0;
    }

string InfixToPostfix(  string & infix) {
    string postfix;
    //scan from left to right coz it we wnat transfer it to post fix
    for(int i=0 ; i<infix.length() ; i++) {
        if(infix[i] ==' ')
            continue;
            else if( (infix[i] >='a' && infix[i] <='z') || (infix[i]>='A' && infix[i] <='Z' ))
                postfix+=infix[i];
                
            else if(infix[i]=='(')
                push(infix[i]);
                
            else if(infix[i]==')') {
                while((!is_empty() )&& (top_fun() != '(' ) ) {
                    postfix+=top_fun();
                    pop();
                }
                //s.pop();
                if(top_fun()=='(')
                    pop();
            }
            else if(is_operater(infix[i])) {
                if(is_empty())
                    push(infix[i]);
                else {
                    
                    if(precedence(infix[i]) > precedence(top_fun()))
                        push(infix[i]);
                    else  {
                        while(!is_empty() && precedence(infix[i]) <= precedence(top_fun()))  {
                            postfix+=top_fun();
                            pop();
                        }
                        push(infix[i]);
                    }
                }
            }else 
                continue;
    }
    while(is_empty()) {
        postfix+=top_fun();
        pop();
    }
    return postfix;
}

};
  
int main()
{
    string  postfix_exp;
	string infix_exp = ("k+l-m*n+(o^p)*w/u/v/*t+Q");
    stack s(infix_exp.length());
	cout<<"INFIX EXPRESSION: "<<infix_exp<<endl;
  	postfix_exp = s.InfixToPostfix( infix_exp);
  	cout<<endl<<"POSTFIX EXPRESSION: "<<postfix_exp;
	  
	return 0;

}
/*
string InfixToPostfix(stack & s , string infix) {
    string postfix;
    for(int i=0 ; i<infix.length() ; i++) {
        if(infix[i]==' ')
            continue;
            else if( (infix[i]>='a' && infix[i]<='z') || ( infix[i] >='A' && infix[i] <='Z'  ) )
 
                postfix+=infix[i];
                else if(infix[i]=='(')
                    s.push(infix[i]);
                    else if(infix[i]==')') {
                        while(!s.empty() && s.top()!='(') {
                            postfix+=s.top();
                            s.pop();
                        }
                        if(s.top()=='(')
                            s.pop();
                    }
                    else if(is_operater(infix[i])) {
                        if(precedence(infix[i] > precedence(s.top())) )
                            s.push(infix[i]);
                            else  {
                                while(!s.empty() && precedence(infix[i] <= precedence(s.top())) ) {
                                    postfix+=s.top();
                                    s.pop();
                                }
                                s.push(infix[i]);
                            }
                    }
                    else 
                        continue;
                }
                while(!s.empty()) {
                    postfix+=s.top();
                    s.pop();
                }
                return postfix;
    
}
 

int main()
{
    string  postfix_exp;
	string infix_exp = ("k+l-m*n+(o^p)*w/u/v/*t+Q");
    stack s(infix_exp.length());
	cout<<"INFIX EXPRESSION: "<<infix_exp<<endl;
  	postfix_exp = InfixToPostfix(s, infix_exp);
  	cout<<endl<<"POSTFIX EXPRESSION: "<<postfix_exp;
}
*/