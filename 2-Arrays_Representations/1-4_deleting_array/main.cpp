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
int deleting_index(array * arr , int index) {
    int num;
    if(index >=0 && index < arr->counter) {
        int i;
        num=arr->arr[index];
        for(i=index ; i < arr->counter -1 ; i++) {
            arr->arr[i]=arr->arr[i+1];
        }
        arr->counter--;
         return num;
    }else 
        return 0;
}

int main()
{
	 array arr={{1,2,3,4,5},10,5};
     display(arr);
     int num= deleting_index(&arr ,4);
     if(num !=0)
         cout<<"number has been deleted "<<num<<endl;
         else 
             cout<<"out of range"<<endl;
     display(arr);
     
}

/*
 int is_here(array arr, int number) {
     for(int i=0 ; i<arr.counter ;i ++) {
         if(arr.arr[i]==number)
             return i;
     }
     return -1;
 }
 
 bool deleting(array &arr ,  int number) {
       int index= is_here(arr, number);  
       if(index >=0 && index < arr.counter) {
          int i;
          for(i = index ; i <arr.counter-1 ; i++)
              arr.arr[i]=arr.arr[i+1];
         arr.counter--;
         return true;
      
      
     }
      return false;
 }
int main()
{  
  array arr={{1,2,3,4,5},10,5};
  display(arr);
  if( deleting(arr,4))
      cout<<"true"<<endl;
  display(arr );
  
}*/
