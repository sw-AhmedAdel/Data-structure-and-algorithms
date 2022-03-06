#include <iostream>
using namespace std;
// 5  3
class node {
    int data;
    node * next;
public:
    node * head=0 , *new_node;
    void inserting_in_sorted() {
        int choice =1;
        while(choice ==1) {
            new_node=new node;
            cout<<"enter the number"<<endl;
            cin >> new_node->data;
            new_node->next=0;
            if(head ==0) {
                head=new_node;
            }
            else if(new_node->data < head->data) {
                 new_node->next=head;
                 head=new_node;
            }
            else {
              node * temp = head;
              node * prev;
              while(temp && temp->data < new_node->data) {
                  prev=temp;
                  temp=temp->next;
              }
              new_node->next=prev->next;
              prev->next=new_node;
             }
 
            
             cout<<"want again"<<endl;
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
	 node n;
     n.inserting_in_sorted();
     n.display();
}
