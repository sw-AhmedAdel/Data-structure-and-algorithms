#include <iostream>
#include <string>
using namespace std;


/*void print_duplicates(int arr[], int n) {
    int dub=0;
    for(int i=0 ;i< n-1 ;i++) {
        if(arr[i]==arr[i+1] && arr[i]!=dub)
        { 
            dub=arr[i];
            cout<<dub<<endl;
        } else 
            continue;
       
    }
}
*/
void print_duplicates(int arr[], int n) {
     int j=0;
     for(int i=0 ; i<n-1 ; i++) {
         if(arr[i]==arr[i+1]) {
             j=i+1;
             while(arr[j]==arr[i]) {
                 j++;
             }
             cout<<"dub numbers is "<<arr[i]<<": counter is "<<j-i<<endl;
             i=j;
          }
     }
}


int main()
{
  int n{10};//0 1 2 3 4  5  6  7  8  9  
  int arr[n]={3,6,8,8,10,12,15,15,15,20};
  print_duplicates(arr,n);	
}
