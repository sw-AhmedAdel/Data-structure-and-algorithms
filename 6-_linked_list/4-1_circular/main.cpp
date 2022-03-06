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
         new_node->next= new_node;
         new_node->prev= new_node ;
         if(head==0) {
             head=temp=new_node;
             temp->next=head;
             head->prev=temp;
         }
         else {
             new_node->data=arr[i];
             new_node->prev=temp;
             temp->next=new_node;
             temp=new_node;
             temp->next=head;
             head->prev=temp;
         }
         i++;
     }
  }
   
  
  void display() {
      node * temp = head;
      do {
          cout<<temp->data<<endl;
          temp=temp->next;
      } while(temp != head);
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
    
     
}
