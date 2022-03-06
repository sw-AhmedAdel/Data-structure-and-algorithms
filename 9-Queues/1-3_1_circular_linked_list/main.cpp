#include <iostream>
using namespace std;

class node {
private:
    int data;
    node * next;
    node * prev;
public:
   node *front=0,*rear=0 , *new_node;
   bool is_empty() {
       if(front==0 && rear==0)
           return true;
           else 
               return false;
   }
   int get_num() {
       int x;
       cin>>x;
       return x;
   }
   void enqueue() {
       new_node=new node;
       new_node->data=get_num();
       new_node->next=NULL;
       new_node->prev=NULL;
       if(front==0)
           front=rear=new_node;
           else {
               new_node->prev=rear;
               rear->next=new_node;
               rear=new_node;
           }
   }
   
   void dequeue() {
       if(is_empty())
           cout<<"null node"<<endl;
           else if(front ==rear) {
               front=rear=0;
               cout<<"deleted all node"<<endl;
           }else {
               node * t= front;
               front=front->next;
               front->prev->next=NULL;
               front->prev=NULL;
               delete t;
           }
   }
void display() {
    node * t=front;
    while(t!= NULL) {
        cout<<t->data<<endl;
        t=t->next;
    }
  } 
 };


int main()
{
	 node q;
     int c;
     do {
         cout<<"1 insert"<<endl;
         cout<<"2- delete"<<endl;
         cout<<"3 display"<<endl;
         cin >> c;
         switch(c) {
             case 1:
             q.enqueue();
             break;
             case 2:
             q.dequeue();
             break;
             case 3:
             q.display();
             break;
             case 0:
             cout<<"exit"<<endl;
             break;
             default:
             cout<<"error try again"<<endl;
             cin >> c;
         }
     }while(c!= 0);
}
