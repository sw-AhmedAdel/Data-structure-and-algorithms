#include <iostream>
#include <string>
using namespace std;

int sum (int n) {
    if(n==0)
        return 0;
        else  {
            return sum(n-1) + n;
         }
}
int main()
{
	std::cout<<sum(5)<<std::endl;
 }
