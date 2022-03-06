#include <iostream>
#include <string>
using namespace std;

struct array {
    int arr[10];
    int size;
    int counter;
};


void display ( struct array * arr) {
    for(int i=0 ; i<arr->counter ; i++)
        cout<<arr->arr[i]<<" ";
 
}
//taken the unique number and put it in one array
bool is_here(array * arr , array *arr_1 , int & i) {
        for(int c=0 ; c<arr->counter ; c++) {
          if(arr->arr[c] ==arr_1->arr[i]) 
                   return false;
        }
        return true;
}
struct  array* union_Array_without_dublicates(array *arr_1, array *arr_2) {
    int siz2e= arr_1->counter + arr_2->counter;
       array *arr_3=new array;
     int i=0 , j=0 ,x =0;
    while(i <arr_1->counter && j < arr_2->counter) {
       
       if(arr_1->arr[i] < arr_2->arr[j] ) {
            arr_3->arr[x]=arr_1->arr[i];
            i++ , x++;
        }
        else  if (arr_2->arr[j] < arr_1->arr[i]){
            arr_3->arr[x] =arr_2->arr[j];
            j++ , x++;
        }
        else {
            arr_3->arr[x] =arr_1->arr[i];
            i++;
            j++;
            x++;
        }
    }
    
    while(i < arr_1->counter) {
           if(is_here(arr_3 ,arr_1 , i))  {
               break;
               
           }
               else {
                   
              arr_3->arr[x]=arr_1->arr[i];
                   i++ ; x++;
               }
    }
     while(j < arr_2->counter) {
             if(is_here(arr_3 ,arr_2 , j))  {
               break;
               
           }
             arr_3->arr[x]=arr_2->arr[j];
            j++ , x++;
    }
    arr_3->size=siz2e;
    arr_3->counter=x;
    return arr_3;
    
}

struct  array* unique_array(array *arr_1, array *arr_2) {
    int size= arr_1->counter + arr_2->counter;
    struct  array *arr_3=new array;
    int i=0 , j=0 ,x =0;
    while(i <arr_1->counter && j < arr_2->counter) {
       
       if(arr_1->arr[i] < arr_2->arr[j] ) {
             i++ ;
        }
        else  if (arr_2->arr[j] < arr_1->arr[i] ){
             j++ ;
        }
        else {
            arr_3->arr[x] =arr_1->arr[i];
            i++;
            j++;
            x++;
        }
    }
    
    
    arr_3->size=size;
    arr_3->counter=x;
    return arr_3;
    
}

struct  array* array_1_unique(array *arr_1, array *arr_2) {
    int size= arr_1->counter + arr_2->counter;
    struct  array *arr_3=(struct array *) malloc(sizeof(struct array));
    int i=0 , j=0 ,x =0;
    while(i <arr_1->counter && j < arr_2->counter) {
     
     if(arr_1->arr[i] < arr_2->arr[j] ) {
            arr_3->arr[x]=arr_1->arr[i];
            i++ , x++;
        }
        else  if (arr_2->arr[j] < arr_1->arr[i]){
            j++;
        }
        else {
             i++;
            j++;
         }
    }
    
    while(i < arr_1->counter) {
            arr_3->arr[x]=arr_1->arr[i];
            i++ , x++;
    }
    
    arr_3->size=size;
    arr_3->counter=x;
    return arr_3;
    
}

int main()
{
    array arr_1 ={{2,6,9,15,25},5,5};
    array arr_2 ={{3,4,6,14,15},5,5};
    array *arr_3;
    arr_3=array_1_unique(&arr_1 , & arr_2);
    display( arr_3);
  
   cout<<endl;
}

