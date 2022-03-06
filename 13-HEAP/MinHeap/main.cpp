#include <iostream>
using namespace std;

class MinHeap {
public:
    int size;
    int counter;
    int *arr;
    MinHeap(int s):size{s} , counter{0} {
        arr=new int [size];
    }
    void search(int x) {
        for(int i=0 ; i<counter ; i++){
            if(arr[i]==x){
                cout<<"value found "<<arr[i]<<endl;
                return;
            }
        }
        cout<<"value was not found"<<endl;
    }
    void print() {
         for(int i=0 ; i<counter ; i++){
             cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    int parent(int i) {
        return (i-1)/2;
    }
     int left(int i) {
        return (i*2)+1;
    }
    int right(int i) {
        return (i*2)+2;
    }
    void swap(int *a , int *b) {
        int temp =*a;
        *a=*b;
        *b=temp;
    }
    void insert(int x) {
        if(counter == size){
            cout<<"heap is full"<<endl;
            return;
        }
        else {
            counter++;
            int i=counter-1;
            arr[i]=x;
            while(i!=0 && arr[parent(i)] > arr[i]) {// just to make it max heap make it bigger than  >
                swap(& arr[parent(i)] ,& arr[i]);
                i=parent(i);
            }
        }
    }
   
    int ExtractMin() {
        if(counter <=0)
            return -1;
        if(counter ==1) {
            counter--;
            return arr[counter];
        }
        int root=arr[0];
        arr[0]=arr[counter-1];
        counter--;
        MinHeapify(0);
        return root;
    }
    void MinHeapify(int i) {
        int l=left(i);
        int r=right(i);
        int smallest=i;
        if(l <counter && arr[l] < arr[i])
            smallest=l;
        if(r<counter && arr[r]<arr[smallest])
            smallest=r;
        if(smallest!=i) {
            swap(&arr[i],& arr[smallest]);
            MinHeapify(smallest);//use heapify on the index
            //that swaped if index 0=15 and index 1=5 so here
            //swaped 5 with 15 so 15 in index 1 so use this method
            //to make sure index 1 < it is right and it is left
        }
    }
    void deleteKey(int i) {
        decreaseKey(i,-1);
        ExtractMin();
    }
    void decreaseKey(int i, int min) {
        arr[i]=min;
        while(i!=0 && arr[parent(i)] > arr[i]){ //arr[i]==-1 
            swap(&arr[i] , &arr[parent(i)]);
            i=parent(i);
        }
    }
    int min_value() {
        return arr[0];
    }
    void hepify_method_insert(int x) {
        if(counter==size) {
            cout<<"full"<<endl;
            return;
        }
        else {
            arr[counter]=x;
            counter++;
            for(int i=(counter-1)/2 ; i>=0 ; i--)
                MinHeapify(i);
        }
    }
 
    void unsorded_arr(int x) {
        if(counter < size) {
        arr[counter]=x;
        counter++;
        
        }else 
            cout<<"full"<<endl;
    }
    void sorted_array() {
         for(int i =(counter-1) /2 ; i>=0 ; i--)
            MinHeapify(i);
    }
    void heap_sort_algorism_for_un_sorted_array() {
     int temp[size];
     for (int j = 0; j < size; j++) {
      //cout<<extractMin()<<" ";
      temp[j] = ExtractMin();
      cout << temp[j] << " ";
       }
    cout<<endl;
    }
    
    void heap_sort_using_swaping(){
        int temp=counter;//here the sort will be from bigger to smaller
        counter=counter-1;
        while(counter >=0) {
        swap(&arr[0] , &arr[counter]);
        counter--;
         MinHeapify(0);
        }
       counter=temp;
    }

};

int main()
{
	int size;
    int x;
    cout<<"enter the size of Min Heap"<<endl;
    cin>>size;
    MinHeap heap(size);
    cout<<"Min Heap has been created "<<endl;
    int choice;
    do {
        cout<<"1- insert in heap"<<endl;
        cout<<"2- search in heap"<<endl;
        cout<<"3- delete in heap "<<endl;
        cout<<"4- get_min in heap"<<endl;
        cout<<"5- extraxt min and use hepify to structure the heap "<<endl;
        cout<<"6- print arr in heap"<<endl;
        cout<<"7- implement heap sort algorihms using hepfiy method "<<endl;
        cout<<"8-heap_sort_using_swaping "<<endl;
        cout<<"9 un un sorted array"<<endl;
        cout<<"10 heap_sort_algorism_for_un_sorted_array"<<endl;
        cout<<"11 heap sort with swap with out deleting"<<endl;
        cout<<"0- exit "<<endl;
        cin>> choice;
        switch(choice) {
            case 1:
       
            heap. sorted_array();
            break;
            case 2:
            cout<<"enter the value to be searched"<<endl;
            cin>>x;
            heap.search(x);
            cout<<"found "<<endl;
            break;
            case 3:
            cout<<"enter the value to delete"<<endl;
            cin>>x;
            heap.deleteKey(x);
            break;
            case 4:
            cout<<"get min value"<<endl;
            cout<<heap.min_value()<<endl;
            break;
            case 5:
            x=heap.ExtractMin();
            cout<<"you extracted "<<x<<endl;
            break;
            case 6:
            heap.print();
            break;
            case 7:
            cout<<"enter the number"<<endl;
            cin>>x;
            heap.hepify_method_insert(x);
            break;
            case 8:
            heap.heap_sort_using_swaping();
            break;
            case 9:
            cout<<"enter the number"<<endl;
            cin>>x;
            heap.unsorded_arr(x);
            break;
            case 10:
            heap.heap_sort_algorism_for_un_sorted_array();
            break;
            case 0:
            cout<<"exit "<<endl;
            break;
            default:
            cout<<"error try again "<<endl;
            break;
        }
    }while(choice!=0);
    
}
