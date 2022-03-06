#include <iostream>
using namespace std;
class node {
    int data;
    node* next;
public:
    node * head=0 , * new_node;
    void create(int arr[] , int n) {
        int i=0;
        while(i < n) {
        new_node=new node;
        new_node->data =arr[i];
        new_node->next=0;
        node * temp;
        if(head ==0) {
            head =temp = new_node;
        } else {
            temp->next=new_node;
            temp=new_node;
        }
          i++;
        }
    }
    void remove_dub() {
        node * temp = head->next;
        node * prev= head;
         while(temp != NULL) {
             if(prev->data == temp->data) {
                 prev->next=temp->next;
                 delete temp;
                 temp=prev->next;
                 
             }
             else {
                 temp=temp->next;
                 prev=prev->next;
             }
         }/*while(temp != NULL) {
            if(prev->data == temp->data) {
                node * f= temp;
                temp=temp->next;
                prev->next=temp;
                delete f;
            }else {
                temp=temp->next;
                prev=prev->next;
            }
        }*/
         
        
    }
  
    void display() {
        node * temp = head;
        while(temp != NULL) {
            cout<<temp->data<<endl;
            temp=temp->next;
        }
    }
};

int main()
{
 node n ;
 int arr[6] = {1,2,2,2,2,5};
 n.create(arr, 6);
 n.display();
 cout<<"___________"<<endl;
 n.remove_dub();
 n.display();
 
}
