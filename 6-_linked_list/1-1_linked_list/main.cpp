#include <iostream>
using namespace std;

class node {
   
public:
     int data;
     node * next;
     node * head;
     node *new_node;
     void create() {
         node * temp;
         head=0;
         int choice=1;
         while(choice == 1) {
             new_node = new node;
             cout<<"enter the data"<<endl;
             cin >> new_node->data;
             new_node->next=0;
             if(head ==0)
                 head = temp = new_node;
              else {
                  temp->next=new_node;
                  temp= new_node;
              }
              cout<<"wanna again "<<endl;
              cin >> choice;
         }
     }
     void create_using_arr(int arr[] , int n) {
         head=0;
         node * temp;
         int i=0;
         while(i < n) {
             new_node=new node;
             new_node->data=arr[i];
             new_node->next=0;
             if(head ==0)
                 head=temp = new_node;
                 else {
                     temp->next=new_node;
                     temp=new_node;
                 }
             i++;
         }
     }
     
     void display() {
         node * temp;
         temp = head;
         while(temp != NULL) {
             cout<<temp->data<<endl;
             temp = temp->next;
         }
     }
     void display_rec(node * head) {
          if(head != NULL) {
             cout<<head->data<<endl;
             display_rec(head->next);
             
             //////
             //display_rec(head);
             //head=head->next;
         }
     }
     int count_nodes(node * head) {
         int c=0;
         node * temp = head;
         while(temp != NULL) {
             c++;
             temp=temp->next;
         }
         return c;
     }
    /* int recursive_count_node(node * head) {
         static int c=0;
         if(head != NULL) {
            c++;
         return recursive_count_node(head->next);
         }
         return c;
         
     }*/
    int recursive_count_node(node * head) {
          if(head ==0) 
          return 0;
        else  return recursive_count_node(head->next) + 1 ;
     
    }
    int get_sum() {
        node * temp=head;
        int total=0;
        while(temp != NULL) {
            total+=temp->data;
            temp=temp->next;
        }
        return total;
    }
    int get_sum_recursive(node * head) {
        if(head ==NULL)
            return 0;
            else 
                return get_sum_recursive(head->next) + head->data;
    }
    
    int get_max() {
        node * temp= head;
        int max= head->data;
        while(temp != NULL) {
            if(temp->data > max)
                max = temp->data;
                else 
                    temp=temp->next;
        }
        return max;
    }
    
    int get_max_rec(node * head) {
        static int max = 0;
        if(head != NULL)
        {
            if(head->data > max)
            {
                max= head->data;
            }
         return get_max_rec(head->next);
           
        }
        return  max;
    }
    
    int linear_search(int n) {
        node * temp= head;
        while(temp != NULL) {
            if(n == temp-> data)
                return n;
                else 
                    temp=temp->next;
        }
        return 0;
    }
    int linear_search_rec(node * head , int n) {
         if(head ==0)
             return 0;
          if(head->data == n)
              return n;
          return linear_search_rec(head->next , n);
          /*if(head !=0)
             {
                if(n==head->data)
                    return head->data;
                else linear_search_rec(head->next , n);
            }
            else 
             return 0;*/
                  
    } 
    //ببعت النود عشان النود هنا بيتغير مكانها فا ببعتها هي مش ببعت الرقم وسعتها لما ابعتها يكون مكنها اتحرك
    node * get_search_and_move(node * head, int n) {
        node * prev=0;
        node * temp=head;
        while(temp != NULL) {
            if(n == temp->data) {
                prev->next= temp->next;
                temp->next=head;
                head=temp;
                return temp;
            }
            else {
                prev=temp;
                temp=temp->next;
            }
        }
        return NULL;
    }
     
};
     node * head ,   * new_node;


int main()
{
    /*cout<<"create linked list"<<endl;
    node n;
    n.create();
    cout<<"___disply it ____"<<endl;
    n.display();*/
    int arr[5]= {1,2,3,4,5};
    node n2;
    cout<<"___create it using array ____"<<endl;
    n2.create_using_arr(arr,5);
    cout<<"____display in loop"<<endl;
    n2.display();
    cout<<"____display in recursive______"<<endl;
    n2.display_rec(n2.head);
    cout<<"____________print number of nodes___________"<<endl;
    cout<<n2.count_nodes(n2.head)<<endl;
    cout<<"print total"<<endl;
    cout<<n2.get_sum_recursive(n2.head)<<endl;
    cout<<"get_max  recursive"<<n2.get_max_rec(n2.head)<<endl;
    cout<<"linear search "<<n2.linear_search(5)<<endl;
    cout<<"linear search recursive  "<<n2.linear_search_rec(n2.head ,3)<<endl;
    node * temp=n2.get_search_and_move(n2.head , 3);
    if(temp != NULL)
        cout<<temp->data<<endl;
    n2.display();
    
}
