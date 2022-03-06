#include <iostream>
using namespace std;

class array {
private:
    int *arr;
    int size;
    int counter;
public:
    array(int s):size{s} {
        arr=new int[size];
        counter=0;
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
    void swap(int *a , int *b) {
        int temp=*a;
        *a=*b;
        *b=temp;
    }
    void Bubble_Sort() {
        int flage;
        for(int i=0 ; i<counter-1 ; i++) {
            flage=0;//use flage coz maybe after the second or the third pass the sorted is done
            //so there is no need to go for the rest of the passess
            for(int j=0 ; j<counter-1-i ; j++) {
                if(arr[j] > arr[j+1]) {
                    swap(& arr[j] ,& arr[j+1]);
                    flage=1;
                }
            }
            if(flage==0) {
                return;
            }
            cout<<"bubble sort is done work"<<endl;
        }
    }
    void free_array() {
        for(int i=0 ; i<counter ;i++)
            arr[i]=0;
        counter=0;
        cout<<"free array is done"<<endl;
    }
};
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
         cout<<"3- use bubble sort"<<endl;
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
             arr.Bubble_Sort();
             break;
             case 4:
             arr.free_array();
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
