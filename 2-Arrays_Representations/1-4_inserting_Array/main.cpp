#include <iostream>
#include <string>
using namespace std;

struct array {
    int arr[10];
    int size;
    int counter;
};

void display(array& arr) {
    for(int i=0 ; i<arr.counter ; i++)
        cout<< arr.arr[i] <<" ";
    cout<<endl;
}

void append(array * arr, int x) {
    if(arr->counter < arr->size) {
        arr->arr[arr->counter++]=x;
        cout<<"number has been added"<<endl;
    }else 
        cout<<"array is full"<<endl;
}

void inserting(array *arr, int index , int x) {
    int i;
     if(index >=0 && index <= arr->counter) {
         for( i=arr->counter ; i> index ; i--) {
             arr->arr[i]= arr->arr[i-1];
         }
         arr->arr[i]=x;
         arr->counter++;
         cout<<"number has been added"<<endl;
     }
}
int main()
{
	array arr={{1,2,3,4,5},10,5};
    append(&arr,6);
    display(arr);
    cout<<"_________"<<endl;
    inserting(&arr,0,50);
        inserting(&arr,2,50);
            inserting(&arr,8,50);

    display(arr);
}


/*struct array {
    int arr[10];
    int size;
    int counter;
};

void display(array& arr) {
    for(int i=0 ; i<arr.counter ; i++)
        cout<< arr.arr[i] <<" ";
    cout<<endl;
}

void append(array  arr, int x) {
    if(arr.counter < arr.size) {
        arr.arr[arr.counter++]=x;
        cout<<"number has been added"<<endl;
    }else 
        cout<<"array is full"<<endl;
}

int main()
{
	array arr={{1,2,3,4,5},10,5};
    append(arr,6);
    display(arr);
}
*/