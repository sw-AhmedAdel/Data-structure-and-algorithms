#include <iostream>
using namespace std;

class node {
public:
   int data;
   node * next;
   node * head, *new_node;
   void create(){
       int choice=1;
       head=0;
       node * temp;
       while(choice == 1) {
           new_node=new node;
           cout<<"enter the number"<<endl;
           cin>>new_node->data;
           new_node->next=0;
           if(head==0)
               head=temp=new_node;
               else {
                   temp->next=new_node;
                   temp=new_node;
               }
               cout<<"_________________"<<endl;
               cout<<"want to try again"<<endl;
               cin >> choice;
       }
   }
   
   void inserting() {
       node * temp;
       node * new_node;
       int pos;
       cout<<"enter the pos"<<endl;
       cin >> pos;
       if(pos ==0)
       {
          new_node=new node;
          cout<<"enter the number"<<endl;  
          cin>> new_node->data;
          new_node->next=head;
          head=new_node;
       }
       else if(pos > 0) {
           temp=head;
           for(int i=0 ; i<pos-1 && temp != NULL ; i++) {
               temp=temp->next;
           }
           if(temp) {
               new_node= new node;
               cout<<"enter the number"<<endl;  
               cin>> new_node->data;
               new_node->next=temp->next;
               temp->next=new_node;
           }else 
               cout<<" out of bound "<<endl;
       }
   }
   void display(){
       node * temp = head;
       while(temp != NULL) {
           cout<<temp->data<<endl;
           temp=temp->next;
       }
   }
};


int main()
{
	 node n;
     n.create();
     n.display();
     n.inserting();
     n.display();
     n.inserting();
     n.display();
     n.inserting();
     n.display();
     n.inserting();
     n.display();

}
