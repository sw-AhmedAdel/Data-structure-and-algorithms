#include <iostream>
#include <string>
using namespace std;


class array{
    int *arr;
    int n;
public:
    array(int s) {
        n=s;
        arr=new int[n*n+1 /2];
    }
        void set(int i,int j,int x)
            {
            if(i>=j)
            arr[i*(i-1)/2+j-1]=x;
            else
            arr[j*(j-1)/2+i-1]=x;
        }
         void display()
            {
            for(int i=1;i<=n;i++)
            {
            for(int j=1;j<=n;j++)
            {
            if(i>=j)
            cout<<arr[i*(i-1)/2+j-1]<<" ";
            else
            {
            /*int k;
            i=j;
            j=i;
            k=j;*/
            cout<<arr[j*(j-1)/2+i-1]<<" ";
            }
            }
            cout<<endl;
            }
            }
} ;
     

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
           cin >> num;
           arr.set(i,j, num);
         }
     }
     
     arr.display();
     
}