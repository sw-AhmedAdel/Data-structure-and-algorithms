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

void swap(int *x , int *y) {
    int temp= *x;
    *x= *y;
    *y=temp;
} 
 
int linear_search(array *arr  ,int key ) {//array & arr
    for(int i=0 ; i<arr->counter ; i++) {
        if(arr->arr[i]==key) {
            swap( & arr->arr[i], & arr->arr[i-1]);
            return i-1;
            
        }
    }
    return -1;
}
 
int main()
{
	 array arr={{20,10,60,40,52},10,5};
     display(arr);
     cout<<"found number and has been moved back : "<<linear_search( &arr,40) <<endl;
     display(arr);
     
}
