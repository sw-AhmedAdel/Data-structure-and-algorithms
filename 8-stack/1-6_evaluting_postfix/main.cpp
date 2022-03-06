#include <iostream>
#include <stack>
// post from right to left
using namespace std;

int operator_evaluting(char c, int op1 , int op2) {
    if(c=='*')
        return op1 * op2;
        else if(c=='/')
            return op1/op2;
            else if(c=='-')
                return op1-op2;
                else 
                    return op1+op2;
} 

int evaluting_postfix(string postfix) {
    stack<int>s;
    for(int i=0 ; i<postfix.length(); i ++) {
        if(isdigit(postfix[i]))
            s.push(postfix[i]-'0');
            else {
                int op2=s.top();
                s.pop();
                int op1=s.top();
                s.pop();
                int g= operator_evaluting(postfix[i], op1,op2);
                s.push(g);
            }
    }
    int g=s.top();
    s.pop();
    return g;
}

int main()
{
	 string postfix {"382/+5-"};//
     cout<<evaluting_postfix(postfix)<<endl;
     
}