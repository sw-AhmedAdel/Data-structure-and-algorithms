#include <iostream>
using namespace std;

class node {
    int data;
    node * next;
public:
    node *front= 0 , *rear =0 , * new_node;
    bool empty() {
        if(front == 0 && rear == 0)
            return true;
            else 
                return false;
    }
    void enqueue() {
        new_node = new node;
        cout<<"enter the num"<<endl;
        cin >> new_node->data;
        new_node->next=0;
        if(rear==0 && front == 0) {
            front=rear= new_node;
        }else {
            rear->next=new_node;
            rear=new_node;
        }
    }
    
    void dequeue() {
        if(empty()) {
            cout<<"empty"<<endl;
        }
        else if(front == rear) {
            cout<<"delete lase node "<<endl;
            front=rear=0;
        }else {
            node * temp;
            temp =front;
            front=front->next;
            cout<<"deleted "<<temp->data<<endl;
            delete temp;
        }
    }
    void display(){
        if(empty()) {
            cout<<"emtpy"<<endl;
        }else {
            node * temp =front;
            while(temp != NULL) {
                cout<<temp->data<<endl;
                temp=temp->next;
            }
        }
    }
};
int main()
{ node q;
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
