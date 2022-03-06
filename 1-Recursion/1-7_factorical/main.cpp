#include <iostream>
#include <string>
using namespace std;


int fact(int n) {
    if(n==0)
        return 1;
        else 
            return fact (n-1)*n;
}

int main()
{
	 cout<<fact(5);
    
}
/* int fact=1;
    int n=5;
    int i=1;
    while(i <= n) {
        fact*=i;
        i++;
    }
    cout<<fact;*/