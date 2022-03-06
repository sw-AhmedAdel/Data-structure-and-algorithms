#include <iostream>
#include <string>
using namespace std;
/*int get_missing_array(int arr[11]) {
    for(int i=1 ; i<11 ; i++) {
        if(arr[i] -1==arr[i-1] )
            continue;
            else 
                return arr[i] -1;
    }
    return 0;
}*/

/*int get_missing_array(int arr[11]) {
    int sum=0;
    int s;
    for(int i=0 ; i<11 ; i++) {
        sum= sum +arr[i];
    }
    cout<<sum<<endl;
     s= arr[10] * (arr[10] +1) /2;
    return s- sum;
}

int main()
{
	 int arr[11]={1,2,3,4,5,6,8,9,10,11,12};/ natrual number starts from 1
     cout<<get_missing_array(arr)<<endl;
}*/

int get_missing_array(int arr[11] , int n) {
    int low=arr[0];
   // int large=arr[n-1];
    int missing= low -0;
    for(int i=0 ; i<n ; i++) {
       if(arr[i]-i != missing)
           return  i+missing;
    }
    return 0;
}

int main(){
    int n=11;
    int arr[n]={6,7,8,9,10,11,12,13,14,16,17};
    cout<<get_missing_array(arr ,  n)<<endl;

    
}