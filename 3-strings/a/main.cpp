#include <iostream>
#include <string>
#include <cstring>
using namespace std;
//captial char starts from 65 to90
//small char starts from 97 to 122
 
int main()
{
    
 char word[] ={"google"};
 int i;
 for(i=0 ; word[i] !='\0' ; i++) {};
 cout<<"number of length is "<<i<<endl;
    
 char name[]={"WELCOME"};
 for(int i=0 ; name[i] !='\0' ; i++)
     name[i]=name[i]+32;
 cout<<name<<endl;// no needs to travers in the char array coz the end char is \0 so it will sotp there
cout<<"_______________________"<<endl;
char words[]={"gOOGle"};
for(int i=0 ; words[i] !='\0' ; i++) {
     if(words[i]>=65 && words[i]<=90)
         words[i]=words[i]+32;
         else if(words[i]>='a' && words[i] <=122)
             words[i]=words[i]-32;
 
}
cout<<words<<endl;

}
