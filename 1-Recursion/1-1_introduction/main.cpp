#include <iostream>
#include <string>
using namespace std;

/*void fun(int x) {
    if(x > 0) {
        cout<<x<<endl;
        fun(x-1);
    }
    cout<<x<<endl;
}
*/
/*void loop_fun(int x) {
    
    while(x > 0) {
        cout<<x<<endl;
        x--;
    }
}*/

/*void fun(int x) {
    if(x > 0) {
         fun(x-1);
        cout<<x<<endl;
       
    }
    cout<<x<<endl;
}*/

void loop_fun(int x) {
    
    int i=1;
    while(i <=x) {
        cout<<i<<endl;
        i++;
    }
}
 
int main()
{
 int x{3};
 loop_fun(x);
}
