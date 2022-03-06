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
   
   void inserting() {
       int choice=1;
       while(choice == 1) {
           new_node=new node;
           cout<<"enter the num "<<endl;
           cin >> new_node->data;
           int pos;
           cout<<"enter the pos"<<endl;
           cin >> pos;
           while(pos< 1 || pos> get_counter() +1) {
               cout<<"Enter right pos"<<endl;
               cin>> pos;
           }
           
           if(pos==1) {
               new_node->next=head;
               head=new_node;
               temp->next=head;
           }
           else   {
               int i=1;
               node * temp= head;
               while(i < pos-1 && temp->next!= NULL) {//temp != null in case there is conditon for the pos
                   temp=temp->next;
                   i++;
               }
               new_node->next=temp->next;
               temp->next=new_node;
           }
         
           cout<<"______________________"<<endl;
           display();
           cout<<"want to insert num again "<<endl;
           cin >> choice;
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
 n.inserting(); 
 
}
