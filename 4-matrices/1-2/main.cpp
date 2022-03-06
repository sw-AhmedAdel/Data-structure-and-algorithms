#include <iostream>
#include <string>
using namespace std;

/* what is digonal matrix it is array has numbers and zero  
1 0 0
0 2 0
0 0 3
but instead of using array this will waste space we use normal array */

/*
struct array {
    int arr[10];
    int size {4};
};

void set_array(array * arr , int i , int j , int x) {
    if(i==j) {
        arr->arr[i-1]=x;
    }
}

int get_number(array arr, int i , int j ) {
    if(i == j) 
        return arr.arr[i-1];
        else 
            return 0;
}

void display(array arr) {
    for(int i=0 ; i< arr.size ; i++) {
        for(int c=0 ; c<arr.size; c ++) {
            if(i == c)
                cout<<arr.arr[i]<<" ";
                else 
                    cout<<"0 ";
        }
        cout<<endl;
    }
}

int main(){
    array arr;
    set_array(& arr,1,1,1);
    set_array(& arr,2,2,2);
    set_array(& arr,3,3,3);
    set_array(& arr,4,4,4);
    display(arr);
    cout<<get_number(arr,2,2)<<endl;
}*/


class array {
private:
    int * arr;
    int size;
public:
    array() {
        size=5;
        arr=new int[5];
    }
    ~ array() {
        delete[] arr;
    }
    int get_size() {
        return size;
    }
    array(int s) {
        size= s;
        arr=new int [size];
    }
    void set(int i , int j , int x) {
        if(i == j) {
            arr[i]=x;
        }
    }
    int get(int i , int j) {
        if(i ==j)
            return arr[i];
    }
    void display() {
        for(int i=0 ; i<size ; i ++) {
            for(int c=0 ; c<size ; c++) {
                if(i == c)
                    cout<<arr[i]<<" ";
                    else 
                        cout<<"0 ";
            }
            cout<<endl;
        }
    }
};

int main(){
    array arr(5);
    int num;
    for(int i=0 ; i<arr.get_size(); i ++) {
        for(int c=0 ;c<arr.get_size() ; c++) {
            if(i== c) {
            cout<<"enter the number"<<endl;
            cin >> num;
            arr.set(i , c , num);
        }
      }
    }
   arr.display();
}