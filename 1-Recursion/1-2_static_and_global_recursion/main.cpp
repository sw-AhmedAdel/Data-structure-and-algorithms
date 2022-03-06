#include <iostream>
#include <string>
using namespace std;

/*int fun(int x) {
    if(x > 0) {
        return fun(x-1)+x ;
    }
    return 0;
}*/

int fun(int x) {
    static int n = 5;
    if(x > 0) {
        return fun(x-1)+n;
    }
    return 0;
}
 
int main()
{
	 int x=5;
     cout<<"number is :"<<fun(x)<<endl;
}
