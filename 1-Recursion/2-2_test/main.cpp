#include <iostream>
#include <string>
using namespace std;

int fun(int n) {
    static int i=1;
    if(n >=5) return n;
    n=n+i;
    i++;
   return fun(n);
}
 
int main()
{

     cout<<fun(1)<<endl;
 
}
