#include <iostream>
using namespace std;

class MaxHeap {
public:
    int size;
    int counter;
    int *arr;
public:
    MaxHeap(int s):size{s} , counter{0} {
        arr=new int[size];
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
    void swap(int *a , int *b) {
        int temp=*a;
        *a=*b;
        *b=temp;
    }
    int left(int i) {
        return (i*2)+1;
    }
    int right(int i) {
        return (i*2)+2;
    }
    int parent(int i) {
        return (i-1) /2;
    }
    void insert(int x) {
        if(counter==size) {
            cout<<"heap is full"<<endl;
            return;
        }
        else {
            int i=counter;
            arr[i]=x;
            counter++;
            while(i!=0 && arr[parent(i)] < arr[i]) {
                swap(&arr[i] , &arr[parent(i)]);
                i=parent(i);
            }
        }
    }
    int ExtractMax() {
        if(counter <=0) {
            return -1;
        }else if(counter==1) {
            counter--;
            return arr[counter];
        }
        int root=arr[0];
        arr[0]=arr[counter-1];
        counter--;
        Heapify(0);
        return root;
    }
    void Heapify(int i) {
        int l=left(i);
        int r=right(i);
        int largest=i;
        if(l < counter && arr[l] > arr[i])
            largest=l;
        if(r<counter && arr[r] > arr[largest])
            largest=r;
        if(largest!=i) {
            swap(&arr[i],&arr[largest]);
            Heapify(largest);
        }
    }
        void deleteKey(int i) {
        deleted_Key(  i, 9999);
        ExtractMax();
    }
    void deleted_Key(int i, int max) {
        arr[i]=max;
        while(i!=0 && arr[parent(i)] < arr[i]) {
            swap(&arr[i] , &arr[parent(i)]);
            i=parent(i);
        }
    }
    void IncreaseKey(int i , int x) {
          arr[i]=x;// index 3=5 it will be 50 and will be max 
          while(i!=0 && arr[parent(i)] < arr[i]) {
            swap(&arr[i] , &arr[parent(i)]);
            i=parent(i);
        }
    }
    
    int max_value(){
        return arr[0];
    }
    void Heapify_Method_build (int x) {
        int i=counter;
        arr[i]=x;
        counter++;
        for(int i=(counter-1)/2 ; i>=0 ; i--) {
            Heapify(i);
        }
    }
    int Heapify_Method_delete() {
        int root=arr[0];
        arr[0]=arr[counter-1];
        counter--;
        for(int i=counter-1 ; i>=0 ; i--) {
            Heapify(i);
        }
        return root;
    }
     void heap_sort_using_swaping(){
        int temp=counter;//here the sort will be from smaller to bigger meand put the largest in the back of the array
        counter=counter-1;
        while(counter >=0) {
        swap(&arr[0] , &arr[counter]);
        counter--;
        Heapify(0);
        }
       counter=temp;
       print();
    }
    void heap_sort_algorism_for_un_sorted_array() {
    //getting sorted using deleting and stored the sorting in array
    int temp[size];
    for (int j = 0; j < size; j++) {
      //cout<<extractMin()<<" ";
      temp[j] = ExtractMax();
      cout << temp[j] << " ";
       }
    cout<<endl;
    }
    
    
};
int main()
{  //15 5 20 1 17 10 30
    int size;
    int x;
    cout<<"enter the size of Min Heap"<<endl;
    cin>>size;
    MaxHeap heap(size);
    cout<<"max Heap has been created "<<endl;
    int choice;
    do {
        cout<<"1- insert in heap"<<endl;
        cout<<"2- search in heap"<<endl;
        cout<<"3- delete in heap "<<endl;
        cout<<"4- get_maz in heap"<<endl;
        cout<<"5- extraxt max and use hepify to structure the heap "<<endl;
        cout<<"6- print arr in heap"<<endl;
        cout<<"7- use faster method >> hepify to make it max faster"<<endl;
        cout<<"8-  use faster method >> hepify to deletet from max heap faster"<<endl;
        cout<<"9 heap_sort_using_swaping"<<endl;
        cout<<"10 heap_sort_algorism_for_un_sorted_array"<<endl;
        cout<<"0- exit "<<endl;
        cin>> choice;
        switch(choice) {
            case 1:
            cout<<"enter the value to be inserted"<<endl;
            cin>>x;
            heap.insert(x);
            break;
            case 2:
            cout<<"enter the value to be searched"<<endl;
            cin>>x;
            break;
            case 3:
            cout<<"enter the value to delete"<<endl;
            cin>>x;
            heap.deleteKey(x);
            break;
            case 4:
            cout<<"get min value"<<endl;
            cout<<heap.max_value()<<endl;
            break;
            case 5:
            x=heap.ExtractMax();
            cout<<"you extracted "<<x<<endl;
            break;
            case 6:
            heap.print();
            break;
            case 7:
            cout<<"enter the number"<<endl;
            cin>>x;
            heap.Heapify_Method_build(x);
            break;
            case 8:
            x=heap.Heapify_Method_delete();
            cout<<"deleted "<<x<<endl;
            break;
            case 9:
            heap.heap_sort_using_swaping();
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
