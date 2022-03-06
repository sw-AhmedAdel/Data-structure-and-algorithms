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
  int get_counter() {
      int counter=0;
      node * temp = head;
      while(temp != NULL) {
          counter++;
          temp=temp->next;
      }
      return counter;
  }
  
  void insert() {
      int choice=1;
      int pos;
      while(choice == 1) {
          new_node= new node;
          cout<<"enter the number"<<endl;
          cin >> new_node->data;
          new_node->prev=0;
          new_node->next=0;
          if(get_counter() == 0) {
              head=new_node;
          }else {
              cout<<"enter the pos"<<endl;
              cin >> pos;
              while(pos<1 || pos > get_counter()+1) {
                  cout<<"enter right pos"<<endl;
                  cin >> pos;
              }
              if(pos==1) {
                   new_node->next=head;
                   head->prev=new_node;
                   head=new_node;
              }else 
                  {
                  int i=1;
                  node * temp =head;
                  while(i < pos-1) {
                      temp=temp->next;
                      i++;
                  }
                   new_node->next=temp->next;
                   new_node->prev=temp;
                if(temp->next!= NULL)
                       temp->next->prev=new_node;
                       
                   temp->next=new_node;
              }
              
          }
          display();
          cout<<"want to insert again"<<endl;
          cin >> choice;
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
     n.insert();     
     
}
