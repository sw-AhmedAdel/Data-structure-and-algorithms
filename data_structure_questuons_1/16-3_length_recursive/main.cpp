#include <iostream>
using namespace std;


int count(char input[]){
    if(input[0]=='\0'){
        return 0;
    }
    return 1 + count(input+1);;
}
int main()
{
	 char str[100]={'a','b','c','d'};//array must have size
     cout<<count(str)<<endl;
}
