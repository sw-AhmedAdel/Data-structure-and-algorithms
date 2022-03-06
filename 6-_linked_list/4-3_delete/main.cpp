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
  void delete_() {
      int choice=1;
      while(choice ==1) {
           node * d;
           if(get_counter() == 1) {
               head=0;
               free(head);
               cout<<"deleted all nodes"<<endl;
               return;
           }else {
               int pos;
               cout<<"enter the pos "<<endl;
               cin >> pos;
               while(pos <1 || pos > get_counter()) {
                   cout<<"enter the right pos"<<endl;
                   cin >> pos;
               }
               if(pos ==1) {
                   d= head;
                   head=head->next;
                   head->prev=temp;
                   temp->next=head;
                   free(d);
               }else {
                   int i=1;
                   d= head;
                   while(i < pos) {
                       d=d->next;
                       i++;
                   }
                   d->prev->next=d->next;
                   if(d->prev->next == head) {
                       temp =d;
                       head->prev=temp;
                   }else {
                       d->next->prev=d->prev;
                   }
                   delete d;
 
               }
            }
            cout<<"__________"<<endl;
            display();
           cout<<"want to delete again"<<endl;
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
      n.delete_();
    
     
}
