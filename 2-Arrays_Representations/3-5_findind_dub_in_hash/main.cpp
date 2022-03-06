#include <iostream>
#include <string>
using namespace std;
#include <vector>

void set_array(int hash_table[] , int max) {
     
       for(int i=0 ;i<=max ; i++)
        hash_table[i]=0;//from 0 to 20 will be 0
        
}
 
void using_hash_Table(int arr[10],vector<int> & numbers, vector<int>& counter , int& max , int n) {
    int hash_table[max];
    set_array(hash_table , max);
    for(int i=0 ;i< n; i++) {
        hash_table[arr[i]]++;
    }
    for(int i=1;i<=max ; i++) {
        if(hash_table[i]>1) {
             numbers.push_back(i);
            counter.push_back(hash_table[i]);
            
        }
    }
} 
 
void display(vector<int> & numbers , vector<int> & counter) {
     for(size_t i=0 ; i<numbers.size() ; i++) 
         cout<<"num of dub "<<numbers[i]<<":"<<"counter is "<<counter[i]<<endl;
}

int main()
{
	 vector<int >numbers;
     vector<int> counter;
     int n{10};
     int arr[n]={3,6,8,8,10,12,15,15,15,20};
     int max=20;
      using_hash_Table(arr, numbers , counter, max , n);
     display(numbers , counter);
}
