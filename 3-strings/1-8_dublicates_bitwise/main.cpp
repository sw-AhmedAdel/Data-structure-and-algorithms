#include <iostream>
#include <string>
using namespace std;


int main()
{
   /* cout<< "shifting the bite "<<endl;
    int h=1;
    h=h<<3;
    cout<<h;
    cout<<"___"<<endl;
    cout<<" using and to get another value"<<endl; 
    int a=10;
    int b=6;
    int c= a&b;
    cout<<c<<endl;
    cout<<"______"<<endl;
    cout<<"using | to get the value of sum the 2 of them"<<endl;
    c=a|b;
    cout<<c<<endl;
    cout<<"_______"<<endl;
    cout<<"using masking with help of and  to see if 1 bite is on or off in the byte"<<endl;
     a=16;
     c=1;
    c=c<<2;
    int x=a&c;
    cout<<x<<endl;
    cout<<"_______"<<endl;
    cout<<"using masking with help of and  to see if 1 bite is on or off in the byte"<<endl;
    int v=1;
    v=v<<4;
    x= a& v;
    cout<<x<<endl;
    cout<<"_______"<<endl;
    cout<<"using merging to set 1 bite in byte with help of |   "<<endl;
    int k=1;
    k=k<<2;
    int y= a|k;
    cout<<y<<endl;
    cout<<endl;
     * */
    cout<<"_______________________________________"<<endl;
    char arr[]="finding";
    int x=0;
    int y=0;
    int i;
    for(i =0 ; arr[i] !='\0' ;i++) {
        x=1;
        x= x << (arr[i]- 97);
        if((x & y) > 0) 
            cout<<"found dub "<<arr[i]<<endl;
            else 
                y=x|y;
    }
    cout<<"__________"<<endl;
    int p=4;
    int o=1;
    o=o<<2;
    cout<<o<<endl;
    if(p==o)
        cout<<"true"<<endl;
        else 
            cout<<"False"<<endl;
    
 

}
