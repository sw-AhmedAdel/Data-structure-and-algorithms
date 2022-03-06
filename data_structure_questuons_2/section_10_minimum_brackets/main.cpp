#include <iostream>
#include <string>
#include <vector>
#include <stack>
 using namespace  std;


string minimum_brackets (string str) {
    vector<char>  chars (str.length(), ' ') ;
    for(int i=0;i<str.length() ; i++)
         chars.push_back( str[i] );
    stack <char> s;
    char open='(';
    char close =')';
   for(int i=0 ; i<chars.size() ; i++) {
       if(chars[i] == close && s.empty()) {
           chars[i]=' ';
       }else if(chars[i] == open)
           s.push(i);
           else if(chars[i]==close && !s.empty())
               s.pop();
    }
     while (!s.empty()) {
         int index = s.top();
         chars[index]=' ';
         s.pop();
     }
    string temp;
    for(int i=0 ; i<chars.size() ; i++) {
        if(chars[i] != ' ')
            temp+=chars[i];
            
    }
    return temp;
  
}


int main()
{
   string str= "lee(t(c)o)de)";
cout<<  minimum_brackets(str) <<endl;
 
}
/* using js  
 * const arr= str.split('');
    const stack=[];
    for(let i = 0 ; i<arr.length; i++) {
        if(arr[i] === '(')
            stack.push(i);
        else if(arr[i] ===')' && stack.length )
            stack.pop();
        else if(arr[i] ===')' )
            arr[i]='';
        
    }
    while(stack.length) {
        const index = stack.pop();
        arr[index]= '';
    }
    
    return arr.join('');*/