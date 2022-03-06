#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

 
 int get_postfix( vector< string >tokens) {
  stack<int> st;
        
        for(int i=0;i<tokens.size();i++){
            
        if(tokens[i]=="+" || tokens[i]=="-" || tokens[i]=="*" || tokens[i]=="/"){
              /// 2 elements
             int v1 = st.top();
            st.pop();
            int v2 = st.top();
            st.pop();
             if(tokens[i]=="+"){
                st.push(v2+v1);  /// push result inside stack
            } 
            else if(tokens[i]=="-"){
                st.push(v2-v1);  /// push result inside stack
            }
             else if(tokens[i]=="*"){
                st.push(v2*v1);  /// push result inside stack
            }
             else if(tokens[i]=="/"){
                st.push(v2/v1);  /// push result inside stack
            }
        }
        
        else {
            /// operands
            st.push(stoi(tokens[i]));
        }
    }
        
    /// one element inside the stack
        
        return st.top();
    }       
 
int main()
{    vector< string >infix{"234567"};
string numbers = accumulate(infix.begin() , infix.end() , string {});
for(int i=0 ; i<numbers.size(); i++) {
     int n= numbers[i]-'0';
     cout<<n<<endl;
   }
 
}
