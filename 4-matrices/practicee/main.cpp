#include <iostream>
#include <string>
using namespace std;


class array {
    int * arr;
    int n;
public:
    array(int s) {
        n = s;
        arr=new int[n*n+1 / 2];
    }
    
    void set(int i, int j , int x) {
         if(i>=j) {
             arr[ i*(i-1) /2 + j-1] =x;
         }
    }
    
    void display(){
        for(int i=1 ; i<=n ; i++) {
            for(int j=1 ; j<=n ; j++) {
                if(i>=j)
                    cout<<arr[i*(i-1)/ 2 + j-1]<<" ";
                else 
                    cout<<arr[j*(j-1)/ 2 + i-1]<<" ";
                    
            }
                    cout<<endl;

        }
         
    }
    int get_num(int i, int j) {
        int n =i*(i-1) / 2 + (j-1);
        return arr[n];
    }
};
int main(){
    int size{3};
    array arr(size);
    for(int i=1 ; i<=size ; i++) {
        for(int j=1 ; j<=size ; j++) {
            if(i>=j) {
        int x;
        cout<<"enter the x"<<endl;
        cin >> x;
        arr.set(i,j,x);  
        
            }
        }
    }
    arr.display();
  
}