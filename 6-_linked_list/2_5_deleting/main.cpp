#include <iostream>
using namespace std;
class node {
    int data;
    node* next;
public:
    node * head=0 , * new_node , * temp;
    void create(int arr[] , int n) {
        int i=0;
        while(i < n) {
        new_node=new node;
        new_node->data =arr[i];
        new_node->next=0;
        if(head ==0) {
            head =temp = new_node;
            temp->next=head;
        } else {
            temp->next=new_node;
            temp=new_node;
            temp->next=head;
        }
          i++;
        }
    }
 
   int get_counter() {
       int counter=0;
       node * temp = head;
     do {
        counter++;
        temp=temp->next;
      }
    while(temp != head);
    
       return counter;
   }
   
   void deleting_() {
       int choice=1;
       while(choice == 1) {
           
        if(get_counter() ==1) 
       {
           head=0;
           cout<<"nodes are deleted"<<endl;
           return;
       }else {
           node * d;
           int pos;
           cout<<"enter the pos"<<endl;
           cin >> pos;
           while(pos< 1 || pos> get_counter() ) {
               cout<<"Enter right pos"<<endl;
               cin>> pos;
           }
           
           if(pos==1) {
               d=head;
               head=head->next;
               temp->next=head;
               free(d);
           }
           else  {
               int i=1;
               node * temp= head;
               node *prev;
                while(i < pos) {
                   prev=temp;
                   temp=temp->next;
                   i++;
               }
               prev->next=temp->next;
               free(temp);
           }
           
           cout<<"______________________"<<endl;
           display();
           cout<<"counter are "<<get_counter()<<endl;
           cout<<"want to delete num again "<<endl;
           cin >> choice;
       }
       }
       
   }
   
    void display() {
    node * temp=head;
    do {
        cout<<temp->data<<endl;
        temp=temp->next;
    }
    while(temp != head);
    }
};

int main()
{
 node n ;
 int arr[5] = {1,2,3,4,5};
 n.create(arr, 5);
 n.display();
 cout<<"___________"<<endl;
 n.deleting_(); 
 
}
