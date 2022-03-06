#include <iostream>
#include <vector>

using namespace std;

class HashTable {
private:
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
    
    void insert_array(int arr[] , int n) {
         for(int i=0 ;i<n ;i++) { 
             insert(arr[i]);
             }
    }
    void insert(int key) {
            int index=get_key(key);
            if(hash[index]!=0) {
              index= LinearProbe(key);
            }
            hash[index]=key;
    }
    
    int  LinearProbe(int key) {
        int index=get_key(key);
        int i=0;
        while(hash[ (index+i) %size] !=0 ){
            i++;
        }
        return (index +i) %size; // retrun the value that = 0 means it is empty
    }
    
    void display(){
        for(int i=0 ;i<size ; i++)
            cout<< i<<":"<<hash[i]<<endl;
    }
    
    int search(int key) {
       int index=get_key(key);
      if(hash[index]==0 ) {
           cout<<"not found"<<endl;
           return -1;
       
       }else {
           int i=1;
       while(hash[(index +i) % size] !=key ){//this is the value iside the hash if not =0 so increase i and the the sec index
       i++;//increase i
       //check if the new index is not 0 if it is not do another loop to check if this value =key ?
       if(hash[(index+i) % size] ==0)
           return -1;
    }
    return (index+i) %size;
    }
    }
    
   /* void delete_(int key) {
        int index=search(key);
        hash[index]=0;
        for(int i=0 ;i<size;i++) {
            if(hash[i]!=0) {
                numbers.push_back(hash[i]);
                hash[i]=0;
            }
        }
        cout<<"deleted "<<key<<endl;
        for(size_t i=0;i<numbers.size();i++)
             insert(numbers[i]);
        numbers.clear();
    }*/
};

int main()
{
    int A[] = {26, 30, 45, 23, 25, 43, 74, 19, 29};
    int n = sizeof(A)/sizeof(A[0]);
    HashTable h;
    h.insert_array(A,n);
    h.display();
    cout<<"value stored in index "<<h.search(74)<<endl;
     
   /* h.delete_(25); 
    cout<<"value stored in index "<<h.search(74)<<endl;
*/

    
}
