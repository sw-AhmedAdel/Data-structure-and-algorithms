#include <iostream>
using namespace std;

void Merge(int arr[], int s, int mid , int e) {
    int i=s;
    int j=mid+1;
    int temp[e+1];
    int counter=s;
    while(i<=mid && j <=e) {
        if(arr[i] <arr[j])
            temp[counter++]=arr[i++];
            else 
                temp[counter++]=arr[j++];
    }
    while(i<=mid) {
        temp[counter++]=arr[i++];
    }
    while(j<=e){
        temp[counter++]=arr[j++];
    }
    for(int i=s; i<=e ;i++){
        arr[i]=temp[i];
    }
}

void mergSort(int arr[] , int s, int e) {
    if(s<e){
        int mid=(s+e)/2;
        mergSort(arr,s,mid);
        mergSort(arr,mid+1,e);
        Merge(arr,s,mid,e);
    }
}

int main()
{
	int size{8};
    int arr[size]= {8,2,9,6,5,3,7,4};
    for(int i=0;i<size;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
    cout<<"sorted"<<endl;
    mergSort(arr,0,size-1);
    for(int i=0;i<size;i++)
        cout<<arr[i]<<" ";
    cout<<endl;
	return 0;
}
