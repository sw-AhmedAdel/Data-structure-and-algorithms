#include <iostream >
#include <string>
using namespace std;
class array {
private:
     int *arr;
     int size;
     int counter;
public:
     array() {
         size=10;
         counter=0;
         arr=new int[size];
     }
     array(int s){
         size=s;
         counter=0;
         arr=new int[size];
     }
     void display() {
         for(int i=0 ; i<counter ; i++){
         cout<<arr[i]<<" ";
    }
    cout<<endl;
     }
     void set_array() {
         for(int i=0 ; i<size ; i++) {
             cout<<"enter the num"<<endl;
             cin>>arr[i];
             counter++;
         }
     }
     void line() {
         cout<<"_________________________"<<endl;
     }
     ~array() {
         delete[] arr;
     }
     void taken_number_from_main(int temp[]) {
         for(int i=0 ; i<5 ;i++) {
             arr[i]=temp[i];
             counter++;
         }
     }
      
    array * merging_in_heap( array arr2) {
        int i,j,k;  
        i=j=k=0;
        array *arr3=new array(counter+arr2.counter);
        while(i<counter && j<arr2.counter) 
           {if(arr[i]<arr2.arr[j])    {     
           arr3->arr[k]=arr[i];
           k++ , i++;
           }
            else    if(arr2.arr[j] < arr[i]) {
               arr3->arr[k]=arr2.arr[j];  
               k++ ,j++;
            }
            else {
            arr3->arr[k]=arr2.arr[j];  
            k++ , j++ ,i++;

            }
          }
          while(i <counter)  {
          arr3->arr[k]=arr[i];
          k++, i++;
          }
             while(j<arr2.counter)
            {   
             arr3->arr[k]=arr2.arr[j];
             k++ , j++;
             }  
           arr3->counter=k;
          return arr3;
     }
     
     ///////////union array without dublicates///////////////
     array * union_array( array arr2) {
        int i,j,k;  
        i=j=k=0;
        array *arr3=new array(counter+arr2.counter);
        while(i<counter && j<arr2.counter) 
           {if(arr[i]<arr2.arr[j])    {     
           arr3->arr[k]=arr[i];
           k++ , i++;
           }
            else    if(arr2.arr[j] < arr[i]) {
               arr3->arr[k]=arr2.arr[j];  
               k++ ,j++;
            }
            else {
            arr3->arr[k]=arr2.arr[j];  
            k++ , j++ ,i++;

            }
          }
          while(i <counter)  {
          arr3->arr[k]=arr[i];
          k++, i++;
          }
             while(j<arr2.counter)
            {   
             arr3->arr[k]=arr2.arr[j];
             k++ , j++;
             }  
           arr3->counter=k;
          return arr3;
     }
     
     ////////////////////dublicates////////
     
      array * dublicates( array arr2) {
        int i,j,k;  
        i=j=k=0;
        array *arr3=new array(counter+arr2.counter);
        while(i<counter && j<arr2.counter) 
           {if(arr[i]<arr2.arr[j])    {     
             i++;
           }
            else    if(arr2.arr[j] < arr[i]) {
               j++;
            }
            else {
            arr3->arr[k]=arr2.arr[j];  
            k++ , j++ ,i++;

            }
          }
           
           arr3->counter=k;
          return arr3;
     }
     
     
     ///////////unique_Array_number_1/////////////////
      array * unique_Array_number_1( array arr2) {
        int i,j,k;  
        i=j=k=0;
        array *arr3=new array(counter+arr2.counter);
        while(i<counter && j<arr2.counter) 
           {if(arr[i]<arr2.arr[j])    {     
           arr3->arr[k]=arr[i];
           k++ , i++;
           }
            else    if(arr2.arr[j] < arr[i]) {
               j++;
            }
            else {
              j++ ,i++;

            }
          }
          while(i <counter)  {
          arr3->arr[k]=arr[i];
          k++, i++;
          }
           
           arr3->counter=k;
          return arr3;
     }

 };
 
 int main() {
    array arr_1(5);
    int temp_arr_1[5]={2,6,9,15,25};
    arr_1.taken_number_from_main(temp_arr_1);
    arr_1.display();
    array arr_2(5);
    int temp_arr_2[5]={3,4,7,11,18};
    arr_2.taken_number_from_main(temp_arr_2);
    arr_2.display();
    array *arr_3;
    arr_3=arr_1.unique_Array_number_1(arr_2);
    arr_3->display();
 
 }
 
 
  /*
int main(){
array arr(5);
array *p=new array(5);
 arr.set_array();
 arr.display();
 arr.line();
 p->set_array();
 p->display();
 p->line();
 
}*/