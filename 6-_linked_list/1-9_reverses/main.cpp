#include <iostream>
using namespace std;
int n=5;
int arr[5];
int counter=0;
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
    void reverse_using_arr() {
        node * temp = head;
        while(temp != NULL) {
            arr[counter] = temp->data;
            counter++;
            temp=temp->next;
        }
         temp = head;
         counter--;
         
        while(temp != NULL) {
            temp->data= arr[counter];
            counter--;
            temp=temp->next;
        }
    }
    void display() {
        node * temp = head;
        while(temp != NULL) {
            cout<<temp->data<<endl;
            temp=temp->next;
        }
    }
    void reserve() {
        node * next= head;
        node* current = NULL;
        node * prev= NULL;
        while(next!= NULL) {
            prev= current;
            current=next;
            next=next->next;
            current->next=prev;
        }
        head=current;
    }
    
    
   /* void recursive(node * next , node * current , node * prev) {
        
        if(next == NULL) 
        {  
            head=current;
        }
            else {
                prev=current;
                current=next;
                recursive(next->next , current , prev);
                current->next=prev;
            }
    }*/
    void recursive(node * current , node * head2) {
        if(head2!=NULL) {
            recursive(head2,head2->next);
            head2->next=current;
        }else 
            head=current;
    }
       
};

int main()
{
 node n ;
 int arr[5] = {1,2,3,4,5};
 n.create(arr, 5);
 n.display();
 cout<<"___________"<<endl;
 node * current=NULL;
 node * prev=NULL;
 //n.recursive(n.head , current , prev);
 n.recursive( current , n.head);

 n.display();
 
}
