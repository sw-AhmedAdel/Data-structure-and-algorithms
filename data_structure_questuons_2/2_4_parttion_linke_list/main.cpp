
#include <iostream>
#include <string>
using namespace  std;


// 1 4 3 2 5 2 >>> make all number less than 3 in left and => in right 1 2 2 4 3 5 in order

class linked_list {
  private:
    linked_list * next;
    int data;
public:
linked_list * head = nullptr ,  * new_node , * tail=nullptr;
   linked_list * create(int arr[] , int size) {
    for(int i=0; i <size ; i++) {
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
 linked_list *  partsion_list(linked_list * A , int x) {
     
        linked_list *head1 = NULL , *tail1 = NULL , *head2 = NULL , *tail2 = NULL;
        
        while(A!=NULL){
            
            if(A->data < x){
                if(head1==NULL){
                    head1=tail1=A;
                }else{
                    /// insert at tail
                    tail1->next = A;
                    tail1 = A;  
                }
            } else {
                if(head2==NULL){
                    head2=tail2=A;
                }else{
                    /// insert at tail
                    tail2->next = A;
                    tail2 = A; /// Lt = LT->next
                }
            }
            
            A = A->next;
        }
        
        /// less and more are ready
        
        if(head1!=NULL && head2==NULL){
             return head1;
        } else if(head1==NULL && head2!=NULL){
                return head2;
        } else if(head1!=NULL && head2!=NULL) {
             tail1->next = NULL;  // coz tail1 will point to 2 and this 2 point to 6 so i need to break this
              tail2->next = NULL;//the same tail2 point to 1 so i need to break it 
            
            tail1 ->next = head2;
            return head1;
        } else{
            return NULL;
        }
        
    }
};


int main()
{
    
    int arr[]={1,4,3,2,5,2 , 6 ,1};
    int size = 8;
    linked_list list;
    linked_list * head = list.create(arr,size);
    list.display(head);
    cout<<"_____________"<<endl;
    linked_list  * new_head = list.partsion_list(head , 3);
    list.display(new_head);
 
    
	return 0;
}


 