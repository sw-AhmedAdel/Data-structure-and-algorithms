#include <iostream>
#include <string>
using namespace std;

/*int pow(int num , int n) {
    if(n==0)
        return 1;
        else 
          return  pow(num ,n-1) *num;
}
*/

int pow(int num , int n) {
    if(n==0)
        return 1;
        else if(n%2==0)
            return pow((num*num) ,(n/2));
            else 
                return num*pow((num*num) ,(n-1)/2);
}

int main()
{
	cout<<pow(2,5)<<endl;
 
}
/*    int i=1;
    int pow=1;
    int n=2;
    int x=5;
    while(i <= x) {
        pow=pow*n;
        i++;
    }
    cout<<pow<<endl;*/