#include <iostream>
using namespace std;
class node {
    int data;
    node* next;
public:
    node * head=0 , * new_node , * head2=0;
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
    }/*    void Concatenating (node * head2) {
         node * temp = head;
         while(temp->next != NULL) {
             temp=temp->next;
         }
         temp->next=head2;
          
         display();
    }*/
    node * Concatenating (node * head2) {
         node * temp = head;
         while(temp->next != NULL) {
             temp=temp->next;
         }
         temp->next=head2;
         return head;
    }
    void display_(node * head){
          node * temp = head;
          while(temp != NULL) {
          cout<<temp->data<<endl;
          temp=temp->next;
    }
    }
    
    node * merging( node * head2) {
        node * temp;
        node * main_head;
        if(head->data < head2->data){
            main_head=temp = head;
            head=head->next;
            temp->next=NULL;
        }else {
            main_head=temp=head2;
            head2=head2->next;
            temp->next=NULL;
        }
        while(head != NULL && head2 != NULL) {
            if(head->data< head2->data) {
                temp->next=head;
                temp=head;
                head=head->next;
                temp->next=NULL;
            }else {
                temp->next=head2;
                temp=head2;
                head2=head2->next;
                temp->next=NULL;
            }
        }
        if(head== NULL ) 
            temp->next=head2;
            else 
                temp->next=head;
        return main_head;
    }
    
};

int main()
{
 node n ;
 int arr_1[5] = {10,20,30,40,50};
 n.create(arr_1, 5);
 n.display();
 cout<<"___________"<<endl;
 node n2;
 int arr_2[4] = {11,15,35,452};
 n2.create(arr_2 ,4);
 n2.display();
  /*node * n3 ; 
 n3= n.Concatenating(n2.head);
 n3->display_(n3);*/
 cout<<"_________________________________"<<endl;
  node *p= n.merging(n2.head);
  p->display_(p);
   
 
}
