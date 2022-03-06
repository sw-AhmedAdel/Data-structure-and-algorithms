#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 /square of 10 is 3  why coz 3*3=9 less than 10
int sqr_binary_Search(int x) {
    int s=1;
    int e= x;
    int temp;
    while(s <=e) {
        int mid = (s+e) /2;
        if(x == mid * mid)
            return mid;
            else if(mid * mid < x) {
                temp=mid;
                s= mid+1;
            }else 
                e= mid-1;
    }
    return temp;
}
 
 
int main()
{ 
    cout<<sqr_binary_Search(10)<<endl;
}
