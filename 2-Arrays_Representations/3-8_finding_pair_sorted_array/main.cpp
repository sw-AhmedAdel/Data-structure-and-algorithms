#include <iostream>
#include <string>
using namespace std;

int main()
{
	int arr[10]={1,3,3,4,6,8,9,10,12,14};
    int k{10};
    int i=0;
    int j=9;
   // while(i < j) {
       for(int i=0 ,  j=9 ; i<j;){
        if(arr[i] + arr[j] > k)
            j--;
        else if(arr[i]+ arr[j] == k) {
            cout<<arr[i]<<"+"<<arr[j]<<"="<<k<<endl;
            i++;
            j--;
        }
        else 
            i++;
    }
}
