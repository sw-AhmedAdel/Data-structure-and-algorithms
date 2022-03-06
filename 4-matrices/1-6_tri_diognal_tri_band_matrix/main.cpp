#include <iostream>
#include <string>
using namespace std;
 
  
 class array {
     int * arr;
     int n;
public:
     array(int s) {
         n=s;
        arr=new int[ 3*n-2];    
        }
     ~array() {
         delete[] arr;
     }
     
     void set(int i, int j , int x) {
         if(i-j == 1)
             arr[i-2]=x;
             else if(i-j==0)
                 arr[n-1 + i-1]=x;
                 else if(i-j==-1)
                     arr[2*n-1 + i-1]=x;
     }

     void display(){
         for(int i=1 ; i<=n ; i++) {
             for(int j=1 ; j<=n ; j++) {
              if(i-j == 1)
             cout<<  arr[i-2]<<" ";
             else if(i-j==0)
                cout<< arr[n-1 + i-1]<<" ";
                 else if(i-j==-1)
                     cout<<arr[2*n-1 + i-1]<<" ";
                     else 
                         cout<<"0 ";
             }
             cout<<endl;
         }
     }
     
     
 };
 
 int main(){
     int size;
     cout<<"enter the size"<<endl;
     cin >> size;
     array arr(size);
     int num;
     for(int i=1 ; i<=size; i++) {
         cout<<"row "<<i<<endl;
         cout<<"_____________"<<endl;
         for(int j=1 ; j<=size ; j++) {
             if(i-j==0 || i-j==1 || i-j==-1) {
           cin >> num;
           arr.set(i,j, num);
         }
     }
     }
     arr.display();
     
 }