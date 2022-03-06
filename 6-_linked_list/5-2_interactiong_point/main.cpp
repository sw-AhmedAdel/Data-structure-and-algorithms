#include <iostream>
#include <stack>
#include <unordered_map>

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
    void interacting_pont(node * head2) {
        node * temp=head2;
        temp=temp->next->next->next->next;
        node *temp_2= head;
        node * prev;
        while(temp_2 != NULL) {
            prev=temp_2;
            temp_2=temp_2->next;
        }
        prev->next=temp;
    }
    
    int get_lenght(node * head) {
        node * temp = head;
        int count =0;
        while(temp != nullptr){
            count ++;
            temp=temp->next;
        }
        return count;
    }
    node * get_the_interacting_point(node * head2) {
        int size_1 = get_lenght(head);
        int size_2 = get_lenght(head2);
        
        int diff = abs(size_1 - size_2);
        if(size_1 > size_2) swap(head , head2);
        //make swap meas make head points to linked list that head 2 ponit to, and head2 pointns to what head points to
        while(diff > 0) {
            head2=head2->next;
        diff--;
        }
     while(head2 != head) {
           head2=head2->next;
           head=head->next;
    if(head2 == head)
             return head;
       
     }
   return nullptr;
       
        
     /*  unordered_map<node* , bool>  map;
       node * current  = head;
       while(current != nullptr) {
           map[current] = true;
           current=current->next;
       }
       current= head2;
       while(current != nullptr) {
           if(map.find(current)==map.end())
               current=current->next;
               else 
                   return current;
       }
        */
        /* node * prev;
        stack<node*> stack1;
        stack<node*> stack2;
        node * temp1=head;
        node* temp2=head2;
        while(temp1 != NULL) {
            stack1.push(temp1);
            temp1=temp1->next;
        }
        while(temp2 != NULL) {
            stack1.push(temp2);
            temp2=temp2->next;
        }
        while(!stack1.empty() && !stack2.empty()) {
            temp1=stack1.top();
            temp2=stack2.top();
            if(temp1 == temp2) {
                  prev= temp1;
                stack1.pop();
                stack2.pop();
            }else 
                break;
        }
        return prev;
        */
        
        /*  node * current = head;
      while(current != nullptr) {
          node * temp = head2;
          while ( current != temp && temp != nullptr) {
              temp=temp->next;
          }
          if(temp == nullptr)
          {
              current= current->next;
          }
          else 
              return current;
      }*/
        
    }
    int get_value(node * t)
    {
        return t->data;
    }
    
    
     
};

int main()
{
 node n ;
 int arr[8] = {8,6,3,9,10,4,2,12};
 n.create(arr, 8);
 n.display();
 cout<<"___________"<<endl;
 node n2;
 int arr_2[3]={20,30,40};
 n2.create(arr_2,3);
 n2.display();
 cout<<"______________________"<<endl;
 n2.interacting_pont(n.head);
  node * temp = n.get_the_interacting_point(n2.head);
 
  cout<<"the intractinge address is "<<temp<<endl;
  cout<<"value is "<<temp->get_value(temp)<<endl;
  
 
}
