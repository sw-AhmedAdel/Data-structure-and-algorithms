#include <iostream>
#include <string>
using namespace std;

bool is_Valied(char  *name) {
    for(int i=0 ; name[i] !='\0' ; i++) {
    if(name[i]>=65 && name[i]<=90 ||name[i]>=97 && name[i]<=122  ||name[i]>=48 && name[i]<=57){
           continue;
       }else 
           return false;
    }
    return true;
}

int main()
{
	 
    char * name={"Nnevergiveup123"};
    if(is_Valied(name))
        cout<<"valied"<<endl;
        else 
            cout<<"not valied"<<endl;
}
