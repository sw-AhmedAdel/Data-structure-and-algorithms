#include <iostream>
#include <string>
using namespace std;

 struct array {
     int arr[5];
     int size;
     int counter;
};

void display(array arr) {
    for(int i=0;i<arr.counter ;i++)
        cout<<arr.arr[i]<<" ";
    cout<<endl;
} 
void reserve_arr_using_array(array &arr) {
    int arr_b[arr.counter];
    for(int i=arr.counter-1 , j=0 ; i>=0 ; i--,j++) {
        arr_b[j]=arr.arr[i];
    }
    for(int i=0 ;i<arr.counter ;i++)
        arr.arr[i]=arr_b[i];
}

void reserve_arr(array & arr) {
    for(int i=0 ,j=arr.counter-1 ; i<j ;i++, j--) {
        int temp =arr.arr[i];
        arr.arr[i]=arr.arr[j];
        arr.arr[j]=temp;
    }
}

void shift_left(array & arr) {
    int temp=arr.arr[0];
    int i;
    for(i=0 ; i<arr.counter-1 ; i++)
        arr.arr[i]=arr.arr[i+1];
    arr.arr[i++]=temp;
}
 
 void shift_right(array & arr) {
    int temp=arr.arr[arr.counter-1];
    int i;
    for(  i=arr.counter-1 ; i>=1 ; i--)
        arr.arr[i]=arr.arr[i-1];
    arr.arr[i]=temp;
}
int main()
{
	 array arr={{1,2,3,4,5},5,5};
     display(arr);
     shift_right(arr);
     display(arr);
     
     
     
}
