#include <iostream>
using namespace std;

class node {
    int data;
    node * next;
public:
    node * head= 0 , * new_node;
    void create() {
        int choice=1;
        while(choice == 1) {
            new_node=new node;
            node * temp ;
            cout<<"enter the number"<<endl;
            cin >> new_node->data;
            new_node->next=0;
            if(head==0) 
                head=temp =new_node;
            else {
                temp->next=new_node;
                temp=new_node;
            }
        cout<<"Want again"<<endl;
        cin >>choice ;
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
    void delete_() {
        int choice=1;
        int pos;
        while(choice ==1) {
        if(head==0) {
            cout<<"no nodes here"<<endl;
            break;
        }
        bool done {false};
        do {
        cout<<"enter the pos"<<endl;
        cin >> pos;
        if(pos >=1 && pos <= get_counter())
            done=true;
            else {
                
                done=false;
            }
        }while(!done);
        
        node * free_;
        if(pos ==1)
        {
            free_=head;
            head=head->next;
            free(free_);
            
        }
            else {
                node * temp=head;
                node * prev;
                for(int i=1 ; i<pos ; i++) {
                    prev=temp;
                    temp=temp->next;
                }
                prev->next=temp->next;
                delete temp;
            }
            display();
            cout<<"___________"<<endl;
        cout<<"want delete again"<<endl;
        cin >> choice;
        
        }
    }
};

int main()
{
node n;
n.create();
n.display();
cout<<"______"<<endl;
n.delete_();	 
}
