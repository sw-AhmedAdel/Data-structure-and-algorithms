#include <iostream>
using namespace std;
 int arr[10]{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
 int fib_1(int n ) {
     if(n<=1)
         return n;
         else {
             if(arr[n-2] ==-1)
                 arr[n-2]=fib_1(n-2);
             if(arr[n-1] ==-1)
                 arr[n-1]=fib_1(n-1);
             return arr[n-2] + arr[n-1];
         }
 }
int a[10]{-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
 int fib_2(int n) {
     a[0]=0 ,a[1]=1;
     for(int i=2 ; i<=n ; i++)
         a[i]=a[i-2] + a[i-1];
     return a[n];
 }
 
int main()
{
	cout<;

}
