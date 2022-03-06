#include <iostream>
#include <string>
using namespace std;

struct array {
    int arr[10];
    int size;
    int counter;
};
void display(array arr) {
    for(int i=0 ; i<arr.counter ; i++)
        cout<<arr.arr[i]<<" ";
    cout<<endl;
}

void inserting_to_sorted_Array(array *arr, int x) {/////// 1
    //moving from left to right;
    int i=arr->counter-1;
    if(arr->counter== arr->size)
        return;
    while(i>=0 && arr->arr[i] > x) {
        arr->arr[i+1]=arr->arr[i];
        i--;
    }
    arr->arr[i+1]=x;
    arr->counter++;
}

    bool is_sorted(array arr) {//2
    for(int i=0 ; i<arr.counter-1 ; i++) {
        if(arr.arr[i] > arr.arr[i+1])
            return false;
    }
    return true;
}


void swap(int *x , int *y) {
    int temp=*x;
    *x=*y;
    *y=temp;
}

void sorted_pos_neg(array *arr) {
    int i=0;
    int j=arr->counter-1;
    while(i< j) {
        while(arr->arr[i]<0)
            i++;
        while(arr->arr[j]>=0)
            j--;
        if(i< j) {
            swap(& arr->arr[i], &arr->arr[j]);
            i++;
            j--;
        }
        
    }
}
int main()
{
	/* 1-  array arr{{4,5,9,12,15,25,80,100} ,10 ,8};
     display(arr);
     inserting_to_sorted_Array(&arr,90);
     display(arr);*/
     
     
   /*  array arr{{4,5,9,12,15,25,50,100} ,10 ,8};
     if(is_sorted(arr))
         cout<<"is sorted"<<endl;
         else 
             cout<<"not sorted"<<endl;*/
             
             
         array arr{{-4,5,9,-12,15,25,-80,-100} ,10 ,8};
         sorted_pos_neg(&arr);
         display(arr);


     
     
}
