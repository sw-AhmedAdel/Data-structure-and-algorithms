#include <iostream>
#include <string>
using namespace std;
class array {
     int * arr;
     int n;
public:
     array(int s) {
         n=s;
        arr=new int[ n*n+1 / 2];    
        }
     ~array() {
         delete[] arr;
     }
     
     void set(int i, int j , int x) {
         if(i<=j) {
         arr[n*(i-1) - (i-2) * (i-1) / 2 + j-1]=x;
        //colum   arr[j*(j-1) / 2 ] =x;
         }
     }
   
     void display(){
         for(int i=1 ; i<=n ; i++) {
             for(int j=1 ; j<=n ; j++) {
                 if(i<=j)
              cout<<arr[n*(i-1) - (i-2) * (i-1) / 2 + j-1]<<" ";
                 // colum cout<<   arr[j*(j-1) / 2 ]<<" ";
                 else 
                     cout<<"0 ";
             }
             cout<<endl;
         }
     }
     
     
 };
 

int main()
{
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
