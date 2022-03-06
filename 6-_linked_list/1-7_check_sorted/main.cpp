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
    bool is_sorted() {
       
        node * current = head;
        node * next = head->next;
        while ( next != nullptr) {
            if(current->data > next-> data)
                return false;
            current = next;
            next= next->next;
        }
        return true;
        /*        while(temp != NULL) {
            if(prev->data < temp->data) {
                temp=temp->next;
                prev=prev->next;
            }else 
                break;
        }
        if(temp == NULL)
            return true;
            else 
                return false;*/
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
 int arr[5] = {1,2,3,4,5};
 n.create(arr, 5);
 n.display();
 if(n.is_sorted())
    cout<<"sorted"<<endl;
    else 
      cout<<"not sorted"<<endl;	 
}
