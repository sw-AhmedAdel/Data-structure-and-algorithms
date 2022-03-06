#include <iostream>
#include <string>
using namespace std;

void f_2(int x);
 
void f_1(int x) {
    if(x > 0) {
        cout<<x<<endl;
        f_2(x-2);
    }
    cout<<"f 1"<<endl;
}

void f_2(int x) {
    if(x  > 0) {
        cout<<x<<endl;
        f_1(x-2);
    }
    cout<<"f 2"<<endl;
}
int main()
{
	f_1(10);
}
