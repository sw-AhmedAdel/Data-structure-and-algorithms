#include <iostream>
using namespace std;

int get_index_of_last_elemet(int arr[], int n , int x , int i ) {
  if(i ==n)
      return -1;
      else {
          int is_found = get_index_of_last_elemet(arr, n , x , i+1);
          if(is_found == -1) {
              if(arr[i] == x)
                  return i;
                  else 
                      return -1;
          }
          return is_found;
      }
    
}

int main()
{
    int arr[] ={1,2,5,4,5,10,9,5,10,4,5};
     cout<<get_index_of_last_elemet(arr,11 , 10 , 0 )<<endl;
}


//get the number of index from the last index start array from the last index 
/*
int get_index_of_last_elemet(int arr[], int n , int x , int i) {
  if(i <0)
      return -1;
      else {
          if(arr[i] == x)
              return i;
              else 
                  return get_index_of_last_elemet(arr, n , x , i-1);
      }
}

int main()
{
    int arr[] ={50,2,5,4,5,10,9,5,10,4,5};
     cout<<get_index_of_last_elemet(arr,11 , 4 , 10)<<endl;
}*/

//i can use just n 
/*
int get_index_of_last_elemet(int arr[], int n , int x) {
 if(n ==0)
     return -1;
     else {
         if(arr[n-1] ==x)
             return n-1;
             else 
                 return get_index_of_last_elemet(arr, n-1 , x);
     }
}

int main()
{
    int arr[] ={50,2,5,4,5,10,9,5,10,4,5};
     cout<<get_index_of_last_elemet(arr,11 ,4)<<endl;
}*/