#include <iostream>
#include <string>
using namespace std;

struct array{
    int arr[10];
    int size;
    int counter;
};


void display(array & arr) {
    for(int i=0 ; i<arr.counter ; i++)
        cout<<arr.arr[i]<<" ";
    cout<<endl;
} 

void sorted_array(array * arr) {
    
    for(int i=0 ; i<arr->counter-1 ; i++) {
        int index=i;
        int value=arr->arr[i];
        for(int c=i+1 ; c<arr->counter ; c++) {
            if(arr->arr[c] < value) {
                value=arr->arr[c];
                index=c;
            }
        }
        int temp=arr->arr[i];
        arr->arr[i]=value;
        arr->arr[index]=temp;
    }
}
int binary_search(array & arr, int key ) {
    int left=0;
    int right=arr.counter-1;
    int mid;
    while(left <= right) {
         mid=(left+right) /2 ;
         if(arr.arr[mid]== key)
             return mid;
             else if(key <arr.arr[mid])
                 right=mid-1;
                 else 
                     left=mid+1;
    }
    return -1;
}
int recursive_search (int arr[], int left, int right, int key ) {
    int mid;
    if(left <= right) {
         mid=(left+right) /2 ;
         if(arr[mid]== key)
             return mid;
             else if(key <arr[mid])
                 recursive_search(arr,left,mid-1, key);
                 else 
                    recursive_search(arr,mid+1,right, key);
                     
    }
    return -1;
}



int main()
{
	 array arr={{20,10,60,40,52},10,5};
     display(arr);
     sorted_array(&arr);
     display(arr);
     cout<<"index is "<<binary_search(arr,52)<<endl;
     
}
