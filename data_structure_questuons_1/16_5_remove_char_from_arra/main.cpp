#include <iostream>
using namespace std;


void remove_char(char str[]) {
    if(str[0]=='\0')
        return;
        else {
            if(str[0]==str[1]) {
                for(int i=0 ;str[i] !='\0' ;i++)
                    str[i]=str[i+1];
                remove_char(str);
            }else 
                remove_char(str+1);
        }
}

//here remove the all char a
/*void remove_char(char str[]) {
    if(str[0] =='\0')
        return;
    if(str[0]!='a')
        remove_char(str+1);
        else {
            for(int i=0; str[i]!='\0' ; i++)
                str[i]=str[i+1];
         remove_char(str);
        }
}
*/
int main()
{
	// char str[100]={'a','b','a','c','a','d','e','f','a'};
    char str[100]={'a','a','b','b','b','c','d','d','k','k'};
     cout<<str<<endl;
     remove_char(str);
     cout<<str<<endl;
}
