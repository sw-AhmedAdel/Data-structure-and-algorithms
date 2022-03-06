#include <iostream>
#include <stack>

using namespace std;

//1- Evaluation of Prefix expression from right to left

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

int evaluting_prefix(string prefix) {
     stack<int> s;
     for(int i=prefix.length()-1 ; i>=0 ; i--) {
         if(isdigit(prefix[i]))
             s.push(prefix[i]-'0');
             else {
                 int op1= s.top();
                 s.pop();
                 int op2=s.top();
                 s.pop();
                 int result = operator_evaluting(prefix[i] , op1, op2);
                 s.push(result);
             }
     }
     int get_result=s.top();
     s.pop();
     return get_result;
}

int main()
{
	 string prefix {"-+2*3+/1623"};
     cout<<evaluting_prefix(prefix)<<endl;
     
}