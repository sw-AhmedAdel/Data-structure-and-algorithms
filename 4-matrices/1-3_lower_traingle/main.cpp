#include <iostream>
#include <string>
using namespace std;
/*lower_traingle 
 * معناها ان على اساس حجم الاراى هيكون فى ارقام وفى اصفار زي
 * 1 0 0 0 0
 * 1 1 0 0 0
 * 1 2 3 0 0
 * 1 2 3 4 0
 * 1 2 3 4 5
 * here to know how many element are not zero by ( n*(n+1) )/ 2; so it will be 5* (6) / 2 = 15
 * but zero number is n squar - (n+1) /2 so it will be 25 -15 = 10 none zero number or n*(n-1) / 2
 * 
 * 
 */
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
         if(i>=j) {
             arr[(i * (i-1) / 2) + j-1]=x;//using raw methods
       //    arr[n *(j-1) -   (j-2) * (j-1) /2  + i-jzz ] =x;
         }
     }
     int get(int i , int j) {
         if(i>=j) {
           return  arr[(i * (i-1) / 2) + j-1];
         }
     }
     void display(){
         for(int i=1 ; i<=n ; i++) {
             for(int j=1 ; j<=n ; j++) {
                 if(i>=j)
                 cout<<arr[ (i* (i-1) / 2) + j-1]<<" ";//  using raw methods
              //         cout<< arr[n *(j-1) -   (j-2) * (j-1) /2  + i-j ]<<" ";

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
             if(i>=j) {
           cin >> num;
           arr.set(i,j, num);
         }
     }
     }
     cout<<arr.get(4,3)<<endl;
     arr.display();
     
 }