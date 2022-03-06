#include <iostream>
using namespace std;
/*

 bool is_found1(int arr[] , int n , int target) {
     if(n==0)
         return false;
     else {
         if(arr[0] == target)
             return true;
             else {
                 return is_found1 (arr+1 ,n-1 , target);
             }
     }
 }
 
 
 bool is_found(int arr[] , int n , int target) {
     if(n==0)
         return false;
     else {
         if(arr[n-1] == target)
             return true;
             else {
                 return is_found (arr ,n-1 , target);
             }
     }
 }
*/

bool is_found(int arr[] , int n , int target) {
     if(n==0)
         return false;
         else {
             bool is_true = is_found(arr+1, n-1 , target );
             if(is_true)
                 return true;
                 else {
                     if(arr[0] == target)
                         return true;
                         else 
                             return false;
                 }
         }
     
 }
int main()
{
	 int arr[] ={1,2,3,4,5,6,7,8,9,10};
     cout<<is_found(arr,10 ,5)<<endl;
}
