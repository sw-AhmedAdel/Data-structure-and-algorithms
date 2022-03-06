#include <iostream>
#include <stack>
#include <string>
using namespace std;



class array {
    int n;
    char * arr;
    int top=-1;
public:
    array(int s) : n{s} {
        arr=new char[n];
    }
 
    void push(char c) {
        if(top == n-1) {
            cout<<"full"<<endl;
            return;
        }else 
        {
            top++;
            arr[top]=c;
        }
    }
    
    char top_ (){
        return arr[top];
    }
    void  pop() {
        if(top ==-1) {
            cout<<"empty"<<endl;
            return ;
        }
        else {
             
            top --;
        }
    }
    
    bool is_empty() {
        if(top==-1)
            return true;
            else 
                return false;
    }
    
  void display() {
      for(int i=top ; i>=0 ; i--)
          cout<<arr[i]<<endl;
  }
  
 /* bool is_macth(string p) {
      for(int i=0 ; p[i]!='\0' ; i++) {
          if(p[i]=='(')
              push(p[i]);
              else if(p[i]==')') {
                  if(is_empty())
                      return false;
                      else 
                          pop();
              }
              continue;
      }
      return true;
  }*/
  bool is_macth(string p) {
     for(int i=0 ; p[i]!='\0' ;i++) {
         if(p[i]=='(' || p[i]=='[' || p[i]=='{')
             push(p[i]);
             else if (p[i]==')' || p[i]==']' || p[i]=='}') {
                    if(is_empty())
                      return false;
                      else  {
                          char t=top_();
                        if(t=='(' && p[i]==')')
                              pop();
                         else if(t=='{' && p[i]=='}')
                             pop();
                             else if(t=='[' && p[i]==']')
                                 pop();
                                 else 
                                     return false;
 
                      }
              }
              continue;
      }
      return true;
  }
};

int main(){
   /* string p={"( (a+b) + (c-d))"};
    int size_p= p.length();
    array arr(size_p);
    if(arr.is_macth(p))
        cout<<"true"<<endl;
        else 
            cout<<"false"<<endl;*/
    string p={" {( [a+b]) + ( [c-d])/e}"};
    int size_p= p.length();
    array arr(size_p);
    if(arr.is_macth(p))
        cout<<"true"<<endl;
        else 
            cout<<"false"<<endl;

}

/*
bool is_match(string p) {
    stack<char>s;
    int i;
    for( i=0 ; p[i]!='\0' ; i++) {
        if(p[i]=='(')
            s.push(p[i]);
        else if(p[i]==')') {
                if(s.empty())
                    return false;
                    else 
                        s.pop();
            }
            else 
                continue;

    }
      return true; 
}

int main()
{
	 string p={"( (a+b) + (c-d))"};
    if( is_match(p))
        cout<<"true"<<endl;
        else 
            cout<<"false"<<endl;
     
}
*/