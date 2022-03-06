#include <iostream>
using namespace std;


class array {
    int size;
    int *arr;
    int counter;
public:
    array(int s):size{s}{
        arr=new int[size];
        counter=0;
    }
    void print(){
        for(int i=0 ; i<counter ;i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }
    
    void merging_2arrays(int a[] , int b[], int size1, int size2) {
        int i=0;
        int j=0;
        while(i <size1 && j <size2) {
            if(a[i] < b[j])
                arr[counter++]=a[i++];
                else 
                    arr[counter++]=b[j++];
        }
        while(i<size1) {
            arr[counter++]=a[i++];
        }
        while(j<size2) {
            arr[counter++]=b[j++];
        }
        print();
    }
  
       void merging_listarray(int a[], int mid,int s , int e) {
        int i=s;
        int j=mid+1;
        while(i<= mid && j<= e) {
            if(a[i] < a[j])
                arr[counter++]=a[i++];
                else 
                    arr[counter++]=a[j++];
        }
        while(i<=mid) {
            arr[counter++]=a[i++];

        }
        while(j<=e) {
            arr[counter++]=a[j++];

        }
        for(int i=0 ;i<=e ;i++)
            a[i]=arr[i];
    }
 

};

int main()
{
	 int size1{5};
     int a[size1] ={2,10,18,20,23};
     int size2{4};
     int b[size2]={4,9,19,25};
     int size=size1+size2;
     array arr(size);
     arr.merging_2arrays(a,b,size1,size2);
     ////////////////////////////////////
     cout<<endl;  // 0 1 2 3  4 5 6  7 
     array arr2(8);
     int arr_arr[8]={2,5,8,12,3,6,7,10};
     int s=0;
     int mid=8/2;
     int e=8;
     arr2.merging_listarray(arr_arr,mid-1,s,e-1);
        for(int i=0 ;i<e ;i++)
            cout<<arr_arr[i]<<" ";
        cout<<endl;
 
      
     
     
}
