#include <iostream>
using namespace std;
class node {
private:
    int data;
    node * next;
public:
    node * head= 0 , * new_node;
    void create() {
        int choice=1;
        while(choice ==1) {
            node * temp;
            new_node=new node;
            cout<<"enter the node"<<endl;
            cin >> new_node->data;
            new_node->next=0;
            if(head==0) {
                head=temp = new_node;
                temp->next=head;
            }else {
                temp->next=new_node;
                temp=new_node;
                temp->next=head;
            }
            cout<<"want again >>>"<<endl;
            cin >> choice;
        }
    }
   /* void display(){
        node * temp;
        temp=head;
        while(temp->next != head) {
            cout<<temp->data<<endl;
            temp=temp->next;
        }
        cout<<temp->data<<endl;
    }
    */
    void display(){
        node * temp;
        temp=head;
        do {
            cout<<temp->data<<endl;
            temp=temp->next;
        }while(temp != head);
         
    }
    void display_rec( node * temp) {
        static int flag=0;
        if(temp != head || flag ==0) {
            flag=1;
            cout<<temp->data<<endl;
            display_rec(temp->next);
        }
        flag=0;
    }
};
int main()
{
	 node n;
     n.create();
     n.display_rec(n.head);
}
