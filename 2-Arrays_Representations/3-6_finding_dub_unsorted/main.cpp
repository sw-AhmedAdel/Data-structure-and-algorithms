#include <iostream>
#include <string>
using namespace std;
/*
void get_dub (int arr[] ,int & counter , int &dub) {
    counter=1;
    int num_dub =0;
    for(int i=0 ; i<10-1 ; i++) {
        for(int c=i+1 ; c<10 ;c++) {
            if(arr[i] == arr[c] && arr[c] != -1 && arr[i] !=-1) {
                dub=arr[c];
                counter++;
                arr[c]=-1;
            }
            if(num_dub < counter)
                num_dub=counter;
        }
        counter=1;
    }
    counter=num_dub;
}
*/

void get_dub (int arr[] ,int & counter , int &dub) {
    counter=1;
     for(int i=0 ; i<10-1 ; i++) {
         if(arr[i] != -1) {
        for(int c=i+1 ; c<10 ;c++) {
            if(arr[i] == arr[c] && arr[c] != -1) {
                 counter++;
                 arr[c]=-1;
            }
             
        }
         if(counter > 1)
                 cout<<arr[i]<<":"<<counter<<endl;
        counter=1;
    }
     }
 }

  
int main()
{
	 int counter;
     int dub;
     int arr[10]={8,3,6,4,6,5,6,8,2,7};
     //get_dub(arr, counter, dub);
     //cout<<"dub num is "<<dub<<": counter "<<counter<<endl;
     cout<<"_____________________________"<<endl;
     int hash[8+1]{0};
     
     for(int i=0 ; i<10 ; i++)
         hash[arr[i]]++;
     for(int i=1 ; i<=8; i++) {
         if(hash[i]> 1)
             cout<<i<<":"<<hash[i]<<endl;
     }
     
}
