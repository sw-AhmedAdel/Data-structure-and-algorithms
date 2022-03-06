#include <iostream>
using namespace std;
 
class node {
public:
    int data;
    node * next;
} ;

class HashTable {
private:
    node ** hash;
public:
    HashTable() {
        hash=new node *[10];
        for(int i=0 ;i<10 ; i++)
            hash[i]=nullptr;
    }
    ~HashTable() {
        for(int i=0 ;i<10 ;i++) {
            while(hash[i] != nullptr) {
                 hash[i]=hash[i]->next;
               
            }
        }
    }
    void display() {
        for(int i=0 ; i<10 ;i++) {
            if(hash[i]!= nullptr) {
            node *temp= hash[i];
            while(temp != nullptr) {
                cout<<temp->data<<" ";
                temp=temp->next;
            }cout<<endl;
            }
        }
    }
    int get_key(int key) {
        return key %10;
    }
    
    void insert(int key) {
        int index= get_key(key);
        node *new_node =new node;
        new_node->data=key;
        new_node->next=nullptr;
        if(hash[index] == nullptr)
            hash[index]=new_node;
            else {
             if(new_node->data < hash[index]->data) {
                new_node->next=hash[index];
                hash[index]=new_node;
            }else {
                node *temp=hash[index];
                node * prev;
                while(temp!= nullptr && temp->data < new_node->data) {
                    prev=temp;
                    temp=temp->next;
                }
                new_node->next=prev->next;
                prev->next=new_node;
            }
            
            }
    }
    
    int search(int key) {
        int index=get_key(key);
        node *temp=hash[index];
        while(temp!= nullptr) {
            if(temp->data == key)
                return temp->data;
                else 
                    temp=temp->next;
        }
        return -1;
    }
    
    void insert_array(int arr[] , int n) {
        for(int i=0 ; i< n ;i++)
            insert(arr[i]);
    }
};

int main() {
	 int A[] = {55, 12, 25, 39, 6, 122, 5, 68, 75};
     int n = sizeof(A)/sizeof(A[0]);
     HashTable h;
     h.insert_array(A,n);
     h.display();
     cout<<"________________"<<endl;
     int key =16;
     cout<<"search for "<<key<<endl;
     if(h.search(key) !=-1)
         cout<<"key was found "<<endl;
         else 
             cout<<"not found"<<endl;
 
}