#include <iostream>
#include <vector>
using namespace std;
/*
bool is_sorted(vector<int> array  , int n , int c) {
    static int i=0;
    if(i == n-1)
        return true;
        else {
            if(array[i] < array[i+1])
                return is_sorted(array, n , i++);
                else 
                    return false;
        }
}*/
/*
//here check array from the first index
bool is_sorted(int array []  , int n) {
 if(n==0 || n==1)
     return true;
 if(array[0] > array[1])
         return false;
  bool check_sorted=  is_sorted(array+1 , n-1);
  //here array +1 means elemenate the first index consider it is not here
  return check_sorted;
}*/

//here check the array from the last 0 1 2 3 4 >> check 3 and 4 index after that 2 and 3 index

bool is_sorted(int array []  , int n) {
 if(n==0 || n==1)
     return true;
 bool sorted = is_sorted(array+1 , n-1);
 if(sorted) {
     if(array[0] > array[1])
     return false;
     else 
         return true;
         
     }
     else
              return false;

 }
   


/*
bool is_sorted(int array []  , int n) {
   if(n==0 || n==1)
     return true;
      
    if(array[n-2] > array[n-1])
          return false; 
    return is_sorted (array, n-1);
}
*/
int main()
{
      int array  []{1,2,3,4,5,6,7,8};
	 cout<<is_sorted(array ,8)<<endl;
}
