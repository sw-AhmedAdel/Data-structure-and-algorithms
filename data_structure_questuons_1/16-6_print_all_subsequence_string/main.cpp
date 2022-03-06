#include <iostream>
#include <string>
using namespace std;
//time is 2 *n and space is 2*n coz each n char will call to make chocie include or exclude 
void print_all_subse(string str, string temp) {
     if(str.length() ==0)
     {   //why will == 0 coz if str =a and i said str.substr(1) index 1 take from it to end but str has 1 char which is a in index 0
         // so i will pass index 0 and go to index 1 that does not have any char and i will take from it to end ?? means this str 
         //has no size coz there is no char in this strig
         if(temp==" ")
             return;
             
         cout<<temp<<endl;
         return;
     }
     print_all_subse(str.substr(1) , temp);
     print_all_subse(str.substr(1) ,temp += str[0]);
}

int main()
{ 
    string str ={"abc"};
    string temp = str.substr(0);
    cout<<temp<<endl;
    cout<<temp.length()<<endl;
    cout<<"_____________"<<endl;
    temp = str.substr(1);
    cout<<temp<<endl;
    cout<<temp.length()<<endl;
    cout<<"_____________"<<endl;
     temp = str.substr(2);
    cout<<temp<<endl;
    cout<<temp.length()<<endl;
    cout<<"_____________"<<endl;
 
       str ={"abc"};
      temp =" ";
    print_all_subse(str , temp);
   
}
