#include <iostream>
using namespace std;


// radix like count sort but it is better for sorting large number like 555 
// in count i must take a temp array and it's size must be the large number in the main aray which is 555+1
//but in radiox no just we will have many passes to sort the largest number more efficint than count

void print(int arr[] , int size) {
    for(int i=0 ;i<size ; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
int get_max(int arr[] , int size) {
    int max=arr[0];
    for(int i=0;i<size ;i++) {
        if(arr[i] > max)
            max=arr[i];
    }
    return max;
}
void countSort(int arr[], int size , int div) {
    int range{10};
    int temp[size];// same size of main arr
    int count[range];//count array from 0 >> 9 alwyas
    for(int i=0;i<range ;i++)
        count[i]=0;
    for(int i=0;i<size ;i++)
        count[(arr[i] / div ) % 10 ]++;//number 259 get 9 and in count array increment 9 index
    for(int i=1;i<range ;i++) {
        count[i]=count[i]+ count[i-1];
    }
    
    for(int i=size-1;i>=0 ;i--) {// go throw the element in the array to put it in temp array using count array
        temp[--count[(arr[i] / div) % 10] ] =arr[i];
    }
    for(int i=0;i<size ;i++)
        arr[i]=temp[i];
}

void Radix_sort(int arr[], int size, int max) {
    for(int div=1 ; max/div >0 ; div= div *10) {
        countSort(arr,size,div);
    }
}
int main()
{
	
    int arr[] = {273,50,214,3007,20,2568,174};
    int size=sizeof(arr)/sizeof(arr[0]);
     print(arr ,size);
    int max = get_max(arr,size);
    Radix_sort(arr,size,max);
    cout<<"____________ USE RADIX SORT ___________"<<endl;
    print(arr,size);
}
