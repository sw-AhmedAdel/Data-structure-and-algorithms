#include <iostream>
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
   
  
    void display() {
        node * temp = head;
        while(temp != NULL) {
            cout<<temp->data<<endl;
            temp=temp->next;
        }
    }
    
    bool is_loob() {
    node * n1 , * n2;
    n1=head->next->next;
    n2=head->next->next->next->next;
    n2->next=n1;
    
    node *move_1 , * move_2;
    move_1 = move_2 = head;
    do {
        move_1=move_1->next;
        move_2=move_2->next;
        if(move_2 != NULL)
            move_2=move_2->next;
            else 
                move_2=NULL;
    }while((move_1 != NULL && move_2 != NULL) && (move_1 != move_2) );
    if(move_1 == move_2)
        return true;
        else 
            return false;
    }
};

int main()
{
 node n ;
 int arr[5] = {1,2,3,4,5};
 n.create(arr, 5);
 n.display();
 cout<<"___________"<<endl;
 if(n.is_loob())
     cout<<"true"<<endl;
     else 
         cout<<"false"<<endl;
  
}
