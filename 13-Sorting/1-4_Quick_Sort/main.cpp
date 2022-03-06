#include <iostream>
using namespace std;

class array {
private:
    int *arr;
    int size;
    int counter;
public:
    int start;
    int end;
    array(int s):size{s} {
        arr=new int[size];
        counter=0;
    }
    void set_counter() {
        start=0;
        end=counter-1;
    }
    void print() {
        for(int i=0 ; i<counter ; i++)
            cout<<arr[i]<<" ";
        cout<<endl;
    }
    void insert(int x) {
        if(counter ==size) {
            cout<<"full"<<endl;
            return;
        }else {
            arr[counter]=x;
            counter++;
        }
    }
    void swap(int *a , int*b) {
        int temp=*a;
        *a=*b;
        *b=temp;
    }
    void Quick_Sort_pivot_end(int s, int e) {
         if(s <e) {
             int p=partition_pivot_end(s,e);
             Quick_Sort_pivot_end(s,p-1);//work in the left side from 0 to index that berofe the pivot
             Quick_Sort_pivot_end(p+1,e);//work in the right side from the index after pivot to the end
         }
    }
    int partition_pivot_end(int s, int e) {
        int pivot=arr[e];
        int pindex=s;
        for(int i=s; i<=e-1 ; i++) {
            if(arr[i] <= pivot) {
                swap(&arr[i],& arr[pindex]);
                pindex++;
            }
        }
        swap(&arr[e], &arr[pindex]);
        return pindex;
    }
    /////////////////////////////////////
    
     void Quick_Sort_pivot_front(int s, int e) {
         if(s<e) {
             int p=partition_pivot_front( s,  e) ;
             Quick_Sort_pivot_front(s,p-1);
             Quick_Sort_pivot_front(p+1,e);
         }
     }
        int partition_pivot_front(int start, int end) {
        int pivot=arr[start];
        int i=start;
        int j=end;
        while(i<j) {
        while(arr[i]<=pivot && i <=end)
            i++;//here if the number <= pivot move coz it is < than and at the end this pivot will be in the middle 
        while(arr[j] > pivot && j >=0)
            j--;//here if number > pivot move why coz when the pivot be in the middle i want to number > than it be in the right
        if(i<j) {
            swap(&arr[i], & arr[j]);
        }
    } 
     swap(&arr[start], & arr[j]);//swap the start pivot with j why coz i corssed j so it means
     // when i corssed j value it mens j value points to number less than pivot so do the swap
     return j;
}
};
//7 9 3 2 6
int main()
{
     int size;
     cout<<"enter the size of the array "<<endl;
     cin >> size;
     array arr(size);
	 int choice;
     int x;
     do {
         cout<<"1- insert the array "<<endl;
         cout<<"2- print the array "<<endl;
         cout<<"3- Quick_Sort_pivot_end"<<endl;
         cout<<"4- Quick_Sort_pivot_front"<<endl;
         cout<<"4 free array"<<endl;
         cin >> choice;
         switch(choice) {
             case 1:
             cout<<"insert number "<<endl;
             cin>>x;
             arr.insert(x);
             break;
             case 2:
             arr.print();
             break;
             case 3:
             arr.set_counter();
             arr.Quick_Sort_pivot_end(arr.start, arr.end);
             cout<<"Quick_Sort_pivot_end is done"<<endl;
             break;
             case 4:
             arr.set_counter();
             arr.Quick_Sort_pivot_front(arr.start,arr.end);
             cout<<"Quick_Sort_pivot_front is done"<<endl;
             break;
             case 0:
             cout<<"exit"<<endl;
             break;
             default:
             cout<<"error"<<endl;
             break;
         }
         
     }while(choice!=0);
}
