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
   int get_counter() {
       node * temp = head;
       int counter=0;
       do {
          counter++;
          temp=temp->next;
      } while(temp != head);
    return counter;
   }
   void display() {
      node * temp = head;
      do {
          cout<<temp->data<<endl;
          temp=temp->next;
      } while(temp != head);
  }   
  void insert() {
      int choice=1;
      while(choice ==1) {
          new_node=new node;
          cout<<"enter the number"<<endl;
          cin >>new_node->data;
          int pos;
          cout<<"Enter the pos"<<endl;
          cin >> pos;
          while(pos < 1 || pos > get_counter()+ 1) {
              cout<<"enter the right pos"<<endl;
              cin >> pos;
          }
          if(pos ==1) {
              new_node->next=head;
              new_node->prev=temp;
              head->prev=new_node;
              head=new_node;
              temp->next=head;
          }else {
              int i=1;
              node * in= head;
              while(i < pos-1) {
                  in=in->next;
                  i++;
              }
              new_node->next=in->next;
              new_node->prev=in;
              in->next=new_node;
              if(new_node->next== head)
              {
                  temp=new_node;
                  head->prev=temp;
              }else {
                  new_node->next->prev=new_node;
              }
                  
                  
              
          }
          cout<<"__________"<<endl;
          display();
          cout<<"want to insert again"<<endl;
          cin >> choice;
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
