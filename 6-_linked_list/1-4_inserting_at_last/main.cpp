#include <iostream>
using namespace std;

class node {
private:
    int data;
    node * next;
public:
    node * head=0 , * new_node;
    void create() {
    int choice=1 ;
    while(choice == 1) {
        new_node=new node;
        node * tail;
        cout<<"enter the num"<<endl;
        cin >> new_node->data;
        new_node->next=0;
        if(head ==0) {
            head  = tail= new_node;
        }else {
             tail->next=new_node;
             tail=new_node;
        }
        cout<<"want again"<<endl;
        cin >> choice;
    }
    /*else {
            node * temp = head;
            node * prev;
            while(temp != NULL) {
                prev= temp;
                temp=temp->next;
                
            }
            prev->next=new_node;
        }*/
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
     n.create();
     n.display();
}
