#include <iostream>
#include <string>
using namespace std;

 /*void swap(char *a , char *b) {
    char temp= *a;
    *a=*a;
    *b=temp;
}

void prem(char s[] , int l , int h) {
    int i;
    if(l== h) {
        cout<<s<<endl;
    }else {
        for(i=l ; i<=h ;i++) {
            swap(s[l] , s[i]);
            prem(s,l+1,h);
            swap(s[l],s[i]);
        }
    }
}

int main(){
    int l=0;
    int h=2;
    char s[] {"abc"};
    prem(s,l,h);
}
*/


void prem(char s[], int k) {
    static int a[10]={0};
    static char rea[10];
    int i;
    if(s[k] =='\0') {
        rea[k]='\0';
        cout<<rea<<endl;
    }
    else {
        for(i=0 ; s[i]!='\0' ; i++) {
            if(a[i]==0) {
                rea[k]=s[i];
                a[i]=1;
                prem(s,k+1);
                a[i]=0;
            }
        }
    }
}
int main()
{
	 int k=0;
     char s[] ={"abc"};
     prem(s,k);
}
