#include <iostream>
using namespace std;
class node {
private:
    int data;
    node * next;
    node * prev;
public:
  node * head=0 , * new_node , * temp;
  void create(int arr[] , int n) {
     int i=0;
     
     while(i < n) {
         new_node=new node;
         new_node->data=arr[i];
         new_node->next=0;
         new_node->prev=0;
         if(head==0) {
             head=temp=new_node;
         }
         else {
             new_node->data=arr[i];
             new_node->prev=temp;
             temp->next=new_node;
             temp=new_node;
         }
         i++;
     }
  }
  void reserve() {
      node * temp , * next;
      temp= head;
      while(temp != NULL) {
          next=temp->next;
          temp->next=temp->prev;
          temp->prev=next;
          temp=temp->prev;
          if( temp != NULL && temp->next == NULL)
              head=temp;
      }
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
     int arr[5] ={1,2,3,4,5};
     n.create(arr, 5);
     cout<<"__________"<<endl;
     n.display();
     cout<<"________"<<endl;
     n.reserve();
     n.display();
     
}
