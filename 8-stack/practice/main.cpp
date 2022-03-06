
#include <iostream>
#include <stack>
using namespace std;


 bool is_macth(string str) {
   stack<char>s;
	 for(int i=0 ;i<str[i]!='\0' ; i++) {
		 if(str[i]=='(' || str[i]=='[' || str[i] =='{') 
			 s.push(str[i]);
		 else if(str[i]==')' || str[i]==']' || str[i] =='}') {
			 if(s.size()==0) {
				 return false;
			 }
			 else {
				 if(s.top()=='(' && str[i]==')')
					 s.pop();
				 else if(s.top()=='[' &&str[i]==']')
					 s.pop();
				 else if(s.top()=='{' && str[i]=='}')
					 s.pop();
			 }
		 }
	 }
	return true;
  }
int main()
{
	    string p={" {( [a+b]) + ( [c-d])/e}"};
        if(is_macth(p))
            cout<<"true"<<endl;
            else 
                cout<<"false";

}
