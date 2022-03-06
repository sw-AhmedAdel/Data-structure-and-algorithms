#include <iostream>
using namespace std;
class node {
private:
    int data;
    node * next;
    node * prev;
public:
  node * head=0 , * new_node , * temp;
  void create() {
      int choice=1;
      while(choice == 1) {
          new_node=new node;
          cout<<"enter the num"<<endl;
          cin >> new_node->data;
          new_node->next=0;
          new_node->prev=0;
          if(head ==0)
              head=temp=new_node;
              else {
                  new_node->prev=temp;
                  temp->next=new_node;
                  temp=new_node;
              }
              cout<<"enter the number  again ? "<<endl;
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
     n.create();
     cout<<"__________"<<endl;
     n.display();
}
