#include <iostream>
#include <vector>
using namespace std;

int parent(int i ) {
    return (i-1)/2;
} 
int left(int i) {
    return (i*2)+1;
}
int right(int i) {
    return (i*2)+2;
}
 
 
void MinHeapify(int i, vector<int> & arr) {
    int l=left(i);
    int r=right(i);
    int smallest=i;
    if(l < arr.size()  && arr[l] < arr[i]){
        smallest=l;
    }
    if(r < arr.size() && arr[r] < arr[smallest])
        smallest=r;
    if(i!= smallest) {
        swap(arr[i], arr[smallest]);
        MinHeapify(smallest,arr);
    }
}
int extract(vector<int> & arr) {
    if(arr.size()<=0)
        return -1;
    else if(arr.size()==1) {
        return arr[0];
        arr.pop_back();
    }else {
        int root=arr[0];
        arr[0]=arr[arr.size()-1];
        arr.pop_back();
        MinHeapify(0,arr);
        return root;
    }
}
vector<int> sort(vector<int> & arr) {
    int size=arr.size();
    vector<int> temp (arr.size() , 0);
    for(int i=0 ; i<size ;i++) {
        temp[i]=extract(arr);
    }
    return temp;
}
void MinHeap(vector<int> & arr) {
    for(int i=(arr.size()-1) /2 ; i<arr.size() ; i++) {
        MinHeapify(0 , arr);
    }
    arr=sort(arr);
} 
 
 vector<int> heapSort(vector<int> & array) {
    MinHeap(array);
    vector<int> arr=array;
    return arr;
}
  
 int main(){
    vector<int> array {8,5,2,9,5,6,3};
    array=heapSort(array);
    for(int i=0 ; i<7 ; i++)
        cout<<array[i]<<endl;
    
    
    
  }

 