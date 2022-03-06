#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
// using arr from 0 to size >> get parent using  (i-1) /2, get left child 2*1+1 ,, right child =2*i+2
void insert(int arr[] ,int x , int & size) {
    int temp=x;
    int i=size;
    while(i>0 && temp >arr[ (i-1) /2  ]) {
        arr[i]=arr[ (i-1) /2 ];
        i=  (i-1) /2 ;
    }
    arr[i]=temp;
    size++;
}
int main() {
  
  int size{9};
  int arr[size]={40,35,15,30,10,12,6,5,20};
  cout<<arr[ (size-1) /2 ]<<endl;
  for(int i=0 ; i<size ; i++)
      cout<<arr[i]<<" ";
cout<<"____________"<<endl;
  insert(arr,50,size);
  cout<<size<<endl;
  for(int i=0 ; i<size ; i++)
      cout<<arr[i]<<" ";

     
}