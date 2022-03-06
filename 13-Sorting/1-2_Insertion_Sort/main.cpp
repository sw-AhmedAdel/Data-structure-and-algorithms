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
 
    void Insertion_Sort() {
         for(int i=1 ; i<counter ; i++) {
             int x=arr[i];
             int j=i-1;
             while(j>=0 && arr[j] > x) {
                 arr[j+1]=arr[j];
                 j--;
             }
             arr[j+1]=x;
         }
         cout<<"insertion sort is done"<<endl;
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
             arr.Insertion_Sort();
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
