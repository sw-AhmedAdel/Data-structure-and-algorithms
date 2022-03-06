#include <iostream>
#include <vector>

using namespace std;

class HashTable {
private:
    vector<int> numbers;
    const static int size{10};
    int hash[size];
public:
    HashTable(){
        for(int i=0;i<size;i++)
            hash[i]=0;
    }
    int get_key(int key) {
        return key % size;
    }
    
    void insert(int key) {
            int index=get_key(key);
            if(hash[index]!=0) {
              index= qurdratic(key);
            }
            hash[index]=key;
    }
    void insert_array(int arr[] , int n) {
         for(int i=0 ;i<n ;i++) { 
             insert(arr[i]);
             }
    }
    int qurdratic(int key) {
        int index=get_key(key);
        int i=0;
        while(hash[ (index+i*i) %size] !=0 ){
            i++;
        }
        return (index +i*i) %size; // retrun the value that = 0 means it is empty
    }
    
    void display(){
        for(int i=0 ;i<size ; i++)
            cout<< i<<":"<<hash[i]<<endl;
    }
    
    int search(int key) {
       int index=get_key(key);
       int i=0;
       while(hash[(index +i*i) % size] !=key ){//this is the value iside the hash if not =0 so increase i and the the sec index
       i++;//increase i
       //check if the new index is not 0 if it is not do another loop to check if this value =key ?
       if(hash[(index+i*i) % size] ==0)
           return -1;
    }
    return (index+i*i) %size;
    }
    
 
};

int main()
{
    int A[] = {23,33,43,27};
    int n = sizeof(A)/sizeof(A[0]);
    HashTable h;
    h.insert_array(A,n);
    h.display();
    cout<<h.search(33)<<endl;
  
    
}
