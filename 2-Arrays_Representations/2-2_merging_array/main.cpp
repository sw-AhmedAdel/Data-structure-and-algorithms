#include <iostream >
#include <string>
using namespace std;
 
 
 struct array {
     int arr[10];
     int size;
     int counter;
     
 };
 void display( struct array *arr) {
    for(int i=0 ; i<arr->counter ; i++)
        cout<<arr->arr[i]<<" ";
    cout<<endl;
}

array * merging_arrays(array *arr_a, array *arr_b) {
    array *arr_c=new array;
    arr_c->size=10;
     int i= 0 , c=0 , x=0;
    while(i < arr_a->counter && c < arr_b->counter) {
        if(arr_a->arr[i] < arr_b->arr[c]) {
            arr_c->arr[x]=arr_a->arr[i];
            i++;x++;
        }else {
            arr_c->arr[x]=arr_b->arr[c];
            c++; x++;
        }
    }
    while(i < arr_a->counter) {
            arr_c->arr[x]=arr_a->arr[i];
            i++;x++;
    }
    while(c < arr_b->counter) {
         arr_c->arr[x]=arr_b->arr[c];
            c++; x++;
    }
        arr_c->counter=x;
    return arr_c;
    
}
  
int main(){
    array arr_1 ={{2,6,9,15,25},5,5};
    array arr_2 ={{3,4,7,11,18},5,5};
    array *arr_3;
    arr_3=merging_arrays(&arr_1 , & arr_2);
    display(arr_3);//send the pointer it self and in display will be pointer 
   

}  
             