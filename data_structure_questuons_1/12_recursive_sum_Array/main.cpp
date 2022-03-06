#include <iostream>
using namespace std;


/*int get_sum(int arr[] , int n) {
    static int sum=0;
    if(n==1)
       return sum+=arr[0];
       else {
           sum+=arr[0];
          return get_sum(arr+1 , n-1);
       }
}*/

/*int get_sum(int arr[] , int n) {
    static int sum=0;
    if(n==1)
       return sum+=arr[0];
       else {
            get_sum(arr+1 , n-1);
            return  sum+=arr[0];
           
       }
 
}*/
/*
int get_sum(int arr[] , int n) {
 if(n==0)
     return 0;
     else 
         return arr[0] + get_sum(arr+1 , n-1);
}*/
/*
int get_sum(int arr[] , int n) {
 if(n==0)
     return 0;
     else 
          return arr[n-1] +get_sum( arr,  n-1 );
}*/
int get_sum(int arr[] , int n , int i) {
 if(i==n)
     return 0;
     else 
          return arr[i] +get_sum( arr,  n , i+1 );
}

int main()
{
	
    int array  []{1,2,3,4,5};
	 cout<<get_sum(array ,5 , 0)<<endl;
}
