#include <iostream>
#include <stack>

using namespace std;
class node {
    int data;
    node* next;
public:
    node * head=0 , * new_node;
    void create(int arr[] , int n) {
        int i=0;
        while(i < n) {
        new_node=new node;
        new_node->data =arr[i];
        new_node->next=0;
        node * temp;
        if(head ==0) {
            head =temp = new_node;
        } else {
            temp->next=new_node;
            temp=new_node;
        }
          i++;
        }
    }
 
    
    int get_counter() {
        node * temp= head;
       int counter=0;
        if(temp ==0)
            return 0;
        while(temp !=0) {
            counter ++;
            temp=temp->next;
        }
        return counter;
    }
    
    void display() {
        node * temp = head;
        while(temp != NULL) {
            cout<<temp->data<<endl;
            temp=temp->next;
        }
    }
     /*int get_middle() {
        int n= get_counter() / 2  ;
        int i=1;
        node * temp =head;
        while(i < n) {
            temp=temp->next;
            i++;
        }
        return temp->data;
        
    }*/
    
    int get_middle() {
        node * current;
        node * move;
        current = move = head;
        while(move != NULL) {
            move = move->next;
            if(move != NULL)
                move=move->next;
            if(move!= NULL)
                current=current->next;
    }
    return current->data;
    }
 int get_middle_using_stack(stack<node *> nodes ) {
   node * temp = head; 
   while(temp != NULL) {
        nodes.push(temp);
        temp=temp->next;
    }

    int size= nodes.size() /2;
    int i=0;
    while( i < size) {
        temp=nodes.top();
        nodes.pop();
        i++;
    }
    return temp->data;
}
    
};
 

int main()
{
 node n ;
 int arr[8] = {4,8,2,9,22,5,7,50};
 n.create(arr, 8);
 n.display();
 cout<<"___________"<<endl;
 cout<<"the middle is "<<n.get_middle()<<endl;
 stack<node * > nodes;
 cout<<"middle using stack is "<<n.get_middle_using_stack(nodes)<<endl;
 
}
