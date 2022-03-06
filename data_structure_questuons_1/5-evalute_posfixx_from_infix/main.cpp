#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

 
 int get_postfix( vector<string> infix) {
     stack<int> s;
     for(int i=0 ; i< infix.size() ; i++) {
         if(infix[i]=="+" || infix[i]=="-" || infix[i]=="*" || infix[i]=="/") {
             int op2=s.top();
             s.pop();
             int op1=s.top();
             s.pop();
             if(infix[i]=="*")
                 s.push(op1 * op2);
                 else if(infix[i]=="+")
                     s.push(op1 + op2);
                     else if(infix[i]=="/")
                         s.push(op1 / op2);
                         else 
                             s.push(op1 - op2);
             
         }else {
             s.push(atoi(infix[i].c_str()));
         }
     }
     return s.top();
 }
 
int main()
{    vector<string> infix{"234*+"};
     cout<<get_postfix(infix)<<endl;
 
}
