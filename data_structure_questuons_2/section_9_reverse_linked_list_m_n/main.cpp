#include <iostream>
#include <string>
using namespace  std;

class linked_list {
  private:
    linked_list * next;
    int data;
public:
linked_list * head = nullptr ,  * new_node , * tail=nullptr;
   linked_list * create(int arr[] , int size) {
    for(int i=0 ; i <size ; i++) {
        if(head ==nullptr) {
            new_node= new linked_list;
            new_node->data=arr[i];
            new_node->next=nullptr;
            head= tail =new_node;
        }else {
            new_node = new linked_list;
            new_node->data=arr[i];
            new_node->next=nullptr;
            tail->next=new_node;
            tail=new_node;
        }
    }
    return head;
}

void display (linked_list * head) {
    linked_list * temp = head;
    while (temp != nullptr) {
        cout<<temp->data<<" "<<endl;
        temp=temp->next;
    }
 }
 linked_list *  reverse(linked_list * head , int m , int n) {
     int pos=1;
     linked_list * current_node = head , * start  = nullptr,  * tail , * next  , *new_list = nullptr;
     while(pos < m) {
         start = current_node;
         current_node=current_node->next;
         pos ++;
     }
     tail = current_node;
     while(pos >= m && pos <=n) {
         next= current_node->next;
         current_node->next=new_list;
         new_list=current_node;
         current_node=next;
         pos++;
     }
 
     start->next=new_list;
     tail->next= current_node;
     if(m > 1)
         return  head;
         else 
             return  new_list;
 }
};


int main()
{
    
    int arr[]={1 ,2 ,3 ,4 ,5 ,6};
    int size = 6;
    linked_list list;
    linked_list * head = list.create(arr,size);
    list.display(head);
    cout<<"_____________"<<endl;
    linked_list  * new_head = list.reverse(head , 2 , 5);
    list.display(new_head);
 
    
	return 0;
}
