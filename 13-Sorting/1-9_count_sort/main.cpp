#include <iostream>
using namespace std;

int find_max(int arr[] , int size) {
    int max=arr[0];
    for(int i=0 ; i<size;i++)
    {
        if(arr[i] > max)
            max=arr[i];
    }
    return max;
}
void print(int arr []) {
    for(int i=0 ; i<10 ;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
void countSearch(int  arr[],int size,int max) {
    int temp[max];
    for(int i=0;i<max;i++)
        temp[i]=0;
    for(int i=0;i<size ;i++)
        temp[arr[i]]++;
    int i=0,j=0;
    while(i<max) {
        while(temp[i] > 0) {
          arr[j++]=i;// the number of index in temp like index 3 has 2 it means in arr number 3 repeated 2 timed
          temp[i]--;
        }
            i++;
    }
}

int main()
{
     int size{10};
	 int arr[size]={6,3,9,10,15,6,8,12,3,6};
     int max=find_max(arr,size);
     max=max+1;
     print(arr);
     cout<<endl;
     countSearch(arr,size,max);
     print(arr);

}
