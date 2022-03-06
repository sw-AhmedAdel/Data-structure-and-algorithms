#include <iostream>
#include <string>
using namespace std;

int fun (int x)  {
    if(x > 100)
        return x -10;
        else 
           return fun(fun(x+11));
}

int main()
{
	 cout<<fun(95)<<endl;
}
