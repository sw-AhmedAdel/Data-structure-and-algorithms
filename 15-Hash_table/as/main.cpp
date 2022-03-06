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
     int get_key2(int key) {
        return 7 - (key % 7);//7 prime number the nearest to 10 
    }
    void insert(int key) {
            int index=get_key(key);
            if(hash[index]!=0) {
              index= DoubleHashing(key);
            }
            hash[index]=key;
    }
    void insert_array(int arr[] , int n) {
         for(int i=0 ;i<n ;i++) { 
             insert(arr[i]);
             }
    }
    int DoubleHashing(int key) {
        int index=get_key(key);
        int index2=get_key2(key);
        int i=0;
        while(hash[(index + i* (index2)) %size ] !=0 ){
            i++;
        }
        return ((index + i* (index2)) %size) ; // retrun the value that = 0 means it is empty
    }
    
    
    void display(){
        for(int i=0 ;i<size ; i++)
            cout<< i<<":"<<hash[i]<<endl;
    }
    
    int search(int key) {
    int index=get_key(key);
        int index2=get_key2(key);
       int i=0;
       while(hash[(index + i* (index2)) %size ] !=key ){//this is the value iside the hash if not =0 so increase i and the the sec index
       i++;//increase i
       //check if the new index is not 0 if it is not do another loop to check if this value =key ?
       if(hash[(index + i* (index2)) %size ] ==0)
           return -1;
      }
      return  ((index + i* (index2)) %size) ;

   }
    
 
};

int main()
{
    int A[] = {5,25,15,35,95};
    int n = sizeof(A)/sizeof(A[0]);
    HashTable h;
    h.insert_array(A,n);
    h.display();
    cout<< h.search(35);  
    // u can increase the number of element> 10
    //double the hash size 20 and take the prime number as 17 
    
}
