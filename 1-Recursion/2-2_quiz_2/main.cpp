#include <iostream>
#include <string>
using namespace std;


void fun(int n , int &sum) {
    int k=0;
    int i=0;
    if(n==0)
        return;
    k= n%10;
    i= n/10;
    sum=sum+ k;
    fun(i,sum);
    cout<<k<<endl;
}
int main()
{
    int sum{0};
    fun(2048, sum);
    cout<<sum<<endl;
}
