#include <iostream>
using namespace std;

class array {
private:
    int *input;
    int *output;
    int size;
    int counter;
    const static int rang{8};//depeonds on the max number in the array which is 7 and add 1 to it >>8
    int countArray[rang];
public:
    int start;
    int end;
    array(int s):size{s} {
        input=new int[size];
        counter=0;
        output=new int[size];
    for(int i=0 ; i<rang ;i++)
        countArray[i]=0;
    }
    void print() {
        for(int i=0 ; i<counter ; i++)
            cout<<input[i]<<" ";
        cout<<endl;
    }
    void insert(int x) {
        if(counter ==size) {
            cout<<"full"<<endl;
            return;
        }else {
            input[counter]=x;
            counter++;
        }
    }
   void Counting_Sort() {
                  //size coz i will get the element form my input array
   for(int i=0 ; i<counter ;i++)//set the count array with values in output array to get the occurances تكرارات element
           countArray[input[i]]++;
  
   for(int i=1 ;i<rang ;i++) //here accumulate the all elements in the count array
       countArray[i]=countArray[i]+countArray[i-1];
   
  for(int i=0 ; i<counter ;i++) {
       output[--countArray[input[i]]]  =input[i];
   }
   for(int i=0 ; i<counter ;i++) {
       input[i]=output[i];
   }
   cout<<"Counting_Sort is done"<<endl;
}
//1 4 1 2 7 5 2
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
         cout<<"3- use Quick sort"<<endl;
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
             arr.Counting_Sort();
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
