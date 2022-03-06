#include <iostream>
using namespace std;

void replace_str(char str[]) {
    if(str[0]=='\0')
        return;
        else {
            if(str[0] =='a'){
                str[0]='x';
            }
            replace_str(str+1);
        }
}

int main()
{
	 char str[100]={'a','b','a','c','a','d','a'};
     cout<<str<<endl;
     replace_str(str);
     cout<<str<<endl;
}
