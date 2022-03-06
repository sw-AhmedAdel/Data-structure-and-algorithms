#include <iostream>
using namespace std;

class node {
    int data;
    node * next;
public:
    node * top=NULL , * new_node;
    void push() {
        int c= 1;
        while(c ==1) {
            new_node = new node;
            cout<<"enter the value"<<endl;
            cin >> new_node->data;
            new_node->next=0;
            if(top == NULL)
                top = new_node;
                else {
                    new_node->next= top;
                    top=new_node;
                }
                cout<<"want to insert again"<<endl;
                cin >> c;
        }
    }
    void display() {
        node * temp= top;
        while(temp != NULL) {
            cout<<temp->data<<endl;
            temp=temp->next;
        }
    }
     int peak(int pos) {
         int i=1;
         node * temp = top;
         while(i < pos  && temp != NULL) {
             temp=temp->next;
             i++;
         }
         if(temp) {
             return temp->data;
         }else 
             return -1;
     }
    void pop(){
        int c= 1;
        while(c ==1) {
            if(top == NULL)
            {
                cout<<"no nodes to be deleted"<<endl;
                return;
            } else {
                node * d= top;
                top=top->next;
                delete d;
                if(top == NULL)
            {
                cout<<"no nodes to be deleted"<<endl;
                return;
            }
            }
            
            cout<<"_______"<<endl;
            display();
              cout<<"want to delete again"<<endl;
              cin >> c;
        }
    }
};
int main()
{
	 node n ;
     n.push();
     cout<<"_____"<<endl;
    cout<< n.peak(4)<<endl;
}
