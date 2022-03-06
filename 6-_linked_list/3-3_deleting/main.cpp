#include <iostream>
using namespace std;
class node {
private:
    int data;
    node * next;
    node * prev;
public:
  node * head=0 , * new_node , * temp;
  void create(int arr[] , int n) {
     int i=0;
     
     while(i < n) {
         new_node=new node;
         new_node->data=arr[i];
         new_node->next=0;
         new_node->prev=0;
         if(head==0) {
             head=temp=new_node;
         }
         else {
             new_node->data=arr[i];
             new_node->prev=temp;
             temp->next=new_node;
             temp=new_node;
         }
         i++;
     }
  }
  int get_counter() {
      int counter=0;
      node * temp = head;
      while(temp != NULL) {
          counter++;
          temp=temp->next;
      }
      return counter;
  }
  
   void  delete_ (){
    int choice =1;
    node * free_;
    if(get_counter() == 0) {
        cout<<"no node to delete"<<endl;
        return;
    }else {
        
        while(choice ==1) {
            if(get_counter() == 1) {
                head=0;
                cout<<"all nodes has been deleted"<<endl;
                break;
            }else {
            int pos;
            cout<<"enter the pos"<<endl;
            cin >> pos;
            while(pos < 1 || pos > get_counter()) {
                cout<<"enter the pos"<<endl;
                cin >> pos;
            }
            if(pos ==1) {
                free_ = head;
                head=head->next;
                head->prev=NULL;
                free(free_);
            }else {
                int i=1;
                node * temp = head;
                while(i < pos) {
                    temp=temp->next;
                    i++;
                }
                //temp is on the node will be delete
                temp->prev->next=temp->next;
                if(temp->next != NULL)
                    temp->next->prev= temp->prev;
                free(temp);
            }  
            cout<<"___________"<<endl;
            display();
            cout<<"want to delete again "<<endl;
            cin >> choice;
        }
         
        }
    }
       
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
     int arr[5] ={1,2,3,4,5};
     n.create(arr, 5);
     cout<<"__________"<<endl;
     n.display();
     cout<<"________"<<endl;
     n.delete_();     
     
}
