#include <iostream>
#include <string>
using namespace std;
struct array {
  int *arr;
  int size;
  int counter;
};

void display(array & a) {
    cout<<"print all number"<<endl;
    for(int i=0 ; i<a.counter ; i++)
        cout<<a.arr[i]<<" ";
    cout<<endl;
}

int main()
{
  array a;
  int size;
  int num_of_element;
  cout<<"enter the size of array"<<endl;
  cin >>size;
  a.size=size;
  a.arr=new int[size];
  a.counter=0;
  cout<<"enter the num of element"<<endl;
  cin >>num_of_element;
  for(int i=0 ; i<num_of_element ; i++) {
      cout<<"enter number "<<i+1<<endl;
      cin >>a.arr[i];
      a.counter++;
  }
 display(a);
 delete [] a.arr;
}

/*struct array {
    int *arr;
    int size;
    int length;
} ;
 void display(array * arr) {
     for(int i=0 ; i<arr->length ; i++)
         cout<<arr->arr[i]<<" ";
    cout<<endl;
 }
int main(){
 
    array arr;
    array *p=new array;
    arr.arr=new int[5];
    p->arr=new int[5];
    arr.length=0;
    p->length=0;
    p->size=5;
    arr.size=5;
    int x=1;
    for(int i=0 ; i<p->size ; i++) {
        p->arr[i]=x;
        arr.arr[i]=x;
        x++;
        p->length++; arr.length++;
    }
    display(p);
    display(& arr);
    
  
}*/
