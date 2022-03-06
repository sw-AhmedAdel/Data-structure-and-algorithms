#include <iostream>
using namespace std;

void print(char str[]) {
    if(str[0]=='\0')
        return;
    print(str+1);
    cout<<str[0]<<endl;
    /* if(n==0)
        return;
        else {
            cout<<str[0]<<endl;
            print(str+1 , n-1);
        }*/
        
}

int main()
{
 char str[100]={'a', 'b', 'c'};
 print(str);
}
