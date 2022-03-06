#include <iostream>
#include <string>
using namespace std;


class node {
    private:
    int data;
    node * next;
    public:
    node * head=0 , * new_node;
    
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
    void insert(int index , int x) {
         if(get_counter() == 0 && index ==0) {
             new_node = new node;
             new_node->data=x;
             new_node->next=0;
             head=new_node;
         }
         else {
             bool done = false;
             do {
              if(index >=0 && index <= get_counter() ) {
                  new_node= new node;
                 if(index ==0) {
                     new_node->data=x;
                     new_node->next=head;
                     head=new_node;
                     done=true;
                 }else if (index <= get_counter() ) {
                     node * temp= head;
                     for(int i=0 ; i<index -1 && temp!=NULL ; i++) {
                         temp=temp->next;
                     }
                     new_node->data=x;
                     new_node->next=temp->next;
                     temp->next=new_node;
                     done=true;
                 }
             }
             else {
                  
                 cout<<"Enter the right index "<<endl;
                 cin >> index;
                 done =false;
                 
             }
             }while(!done);
                 
         }
        
     }
    void display() {
        node * temp=head;
        while(temp != NULL) {
            cout<<temp->data<<endl;
            temp=temp->next;
        }
    }
    
};

int main()
{
	node n;
    n.insert(0,1);
    n.display();
    cout<<"______________"<<endl;
    n.insert(0,2);
    n.display();
    cout<<"_________"<<endl;
    n.insert(0,3);
    n.display();
    cout<<"______________"<<endl;
    n.insert(0,4);
    n.display();
    cout<<"________"<<endl;
    n.insert(5,5);
    n.display();
 
    

}
/*        bool done=false;
        while(!done) {
            if(index>= 0 && index <=get_counter() +1 )
                done=true;
                else {
                    cout<<"try again"<<endl;
                    cin>> index;
                    done=false;
                }
        }*/