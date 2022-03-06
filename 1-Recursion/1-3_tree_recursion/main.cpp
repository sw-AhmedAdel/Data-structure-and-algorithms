#include <iostream>
#include <string>
using namespace std;

void fun(int x) {
    if(x > 0) {
        cout<<x<<endl;
        fun(x-1);
        fun(x-1);
    }
}

int main()
{
	fun(3);
}
