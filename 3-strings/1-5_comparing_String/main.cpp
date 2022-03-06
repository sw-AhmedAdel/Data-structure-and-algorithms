#include <iostream>
#include <string>
using namespace std;

void result(char a[] , char b[]) {
    int i;
    int j;
    for(i=0 ,j=0 ; a[i]!='\0' && b[i]!='\0' ; i++ ,j++) {
        if(a[i]!=b[j])
            break;
    }
    if(a[i]==b[i])
        cout<<"equal"<<endl;
        else if(a[i] < b[i])
            cout<<"char a less than b "<<endl;
            else 
                cout<<"char a bigger than b"<<endl;
}
/*  int i=0;
    int j=0;
    int size=strlen(a);
    while(i < size ) {
        if(a[i]==b[j]){
            i++;
            j++;
            
        }
            else 
                break;
    }
    if(i==size)
        cout<<"trues"<<endl;
        else
            cout<<"false"<<endl;
 */

bool is_palindrom(char word []) {
    int i;
    int j;
    for(i=0 ; word[i]!='\0' ;i++) {
        continue;
    }
    char temp[i];
    i=i-1;
    for(j=0 ; i>=0 ; i-- , j++) {
        temp[j]=word[i];
    }
    temp[j]='\0';
    for(int x=0 ;word[x]!='\0' ; x++) {
        if(word[x]==temp[x])
            continue;
            else 
                return false;
    }
    return true;
}

int main()
{
	 char a[]={"ahmedz"};
     char b[]={"ahmed"};
     result(a,b);
     cout<<"_____________"<<endl;
     char word[]={"madam"};
     if(is_palindrom(word))
         cout<<"is palandrom"<<endl;
         else 
             cout<<"not palandrom"<<endl;
}
