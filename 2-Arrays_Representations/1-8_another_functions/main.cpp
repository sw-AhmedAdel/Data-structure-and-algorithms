#include <iostream>
#include <string>
using namespace std;


struct array {
    int  arr[5];
    int size;
    int counter;
};

void display(array arr) {
    for(int i=0 ; i<arr.counter ; i++)
        cout<<arr.arr[i]<<" ";
    cout<<endl;
}

int get_index( array arr , int index) {
    if(index >=0 && index < arr.counter) {
        return arr.arr[index];
    }
    else 
        return 0;
}

void set_index(array * arr, int index , int x) {
    if(index >=0 && index <arr->counter) {
        arr->arr[index]=x;
        cout<<"number changed"<<endl;
    }else 
        cout<<"out of range"<<endl;
}
int get_sum(array arr) {
    int sum=0;
    for(int i=0 ; i<arr.counter; i++)
        sum+=arr.arr[i];
    return sum;
}
int get_max(array arr) {
    int larg=arr.arr[0];
    for(int i=0 ; i<arr.counter; i++) {
        if(arr.arr[i]> larg)
            larg=arr.arr[i];
    }
    return larg;
}
int get_small(array arr) {
    int s=arr.arr[0];
    for(int i=0 ; i<arr.counter; i++) {
        if(arr.arr[i]< s)
            s=arr.arr[i];
    }
    return s;
}
int recursive_sum(array arr , int n) {
    if(n <0)
        return 0;
        else 
          return  recursive_sum (arr, n-1)+ arr.arr[n];
            
}

int main()
{
    array arr ={{10,30,20,40,90},5,5};
    display(arr);
    cout<<  get_index(arr,4)<<endl;
    set_index( &arr,0,280);
    display(arr);
    cout<<get_sum(arr)<<endl;
    cout<<get_max(arr)<<endl;
    cout<<get_small(arr)<<endl;
    cout<<recursive_sum(arr,arr.counter-1)<<endl;
	 
}
