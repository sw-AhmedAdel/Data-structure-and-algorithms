
#include <iostream>
#include <stack>
using namespace std;

class Node {
public:
    Node* lchild;
    int data;
    Node* rchild;
};

class Queue{
private:
    int front=-1;
    int rear=-1;
    int size ;
    Node **Q;
public:
    Queue(int s) :size{s} {
    Q=new Node *[size];
    }
    ~Queue() 
    {
        delete []Q;
    }
    bool isFull() {
        if(rear == size-1)
            return true;
            else 
                return false;
    }
    bool isEmpty() {
        if(rear ==-1 && front ==-1)
            return true;
            else 
                return false;
    }
    void enqueue(Node* x) {
        if(isFull()) {
            cout<<"is full"<<endl;
        }else if(front ==-1 && rear ==-1) {
            front = rear=0;
            Q[rear]=x;
        }else {
            rear++;
            Q[rear]=x;
        }
    }
   
    Node* dequeue() {
        Node * x= NULL;
        if(isEmpty())
            cout<<"empty"<<endl;
        else if(front == rear) {
            x=Q[rear];
            front=rear=-1;
            return x;
        }else {
            x= Q[front];
            front++;
            return x;
        }
            
    }
    
};

class Tree {
private:
    Node * root;
public:
      Tree() {
          root=nullptr;
      }
      ~Tree(){}
     void CreateTree() {
         Queue q(25);
         Node * temp , * new_node;
         root = new Node;
         cout<<"enter the value of root"<<endl;
         cin>> root->data;
         root->lchild=0;
         root->rchild=0;
         q.enqueue(root);
         while(!q.isEmpty()) {
             temp=q.dequeue();
             int x;
             cout<<"enter the left chiled of "<<temp->data<<endl;
             cin >> x;
             if(x!= -1) {
                 new_node= new Node;
                 new_node->data=x;
                 new_node->lchild=0;
                 new_node->rchild=0;
                 temp->lchild=new_node;
                 q.enqueue(new_node);
             }
             cout<<"enter the right chiled of "<<temp->data<<endl;
             cin >> x;
             if(x!=-1) {
                 new_node=new Node;
                 new_node->data=x;
                 new_node->lchild=0;
                 new_node->rchild=0;
                 temp->rchild=new_node;
                 q.enqueue(new_node);
             }
         }
         
     }
     int count(Node * temp) {
         int x;
         int y;
         if(temp != NULL) {
             x= count(temp->lchild);
             y=count(temp->rchild);
             return x + y + 1;
         }
         else 
             return 0;
     }
       int sum(Node * temp) {
         int x;
         int y;
         if(temp != NULL) {
             x= sum(temp->lchild);
             y=sum(temp->rchild);
             return x + y + temp->data;
         }
         else 
             return 0;
     }
    int count_degree(Node * temp) {
         int x;
         int y;
         if(temp != NULL) {
             x= count_degree(temp->lchild);
             y=count_degree(temp->rchild);
            if(temp->lchild && temp ->rchild)
            //get degree 1 and degree 2 if(temp->lchild || temp ->rchild)
            //get number of leaf node  if(temp->lchild ==nullptr && temp ->rchild==nullptr)
           // get number of degree (1)if(temp->lchild==nullptr && temp ->rchild || temp->lchild && temp ->rchild ==nullptr) 

                 return x+y+1;
                 else 
                     return x+y;
         }
         else 
             return 0;
     }
     int hight(Node * temp) {
         int x=0;
         int y=0;
         if(temp != NULL) {
             x=hight(temp->lchild);
             y=hight(temp->rchild);
             if(x > y )
                 return x+1;
                 else 
                     return y+1;
         }
         return   -1;
         /*  if(temp ==NULL)
         return -1;
         else 
             return hight(temp->lchild) > hight(temp->rchild) ? hight(temp->lchild) +1 : hight(temp->rchild)+1;*/
     }
    void print(Node * root) {
        int num=hight(root);
        for(int i=0 ; i<=num; i ++) {
            print_by_levels(root, i);
        }
    }
    void print_by_levels(Node * root , int i) {
        if(root==NULL)
            return ;
            else {
                if(i==0)
                    cout<<root->data<<" ";
                    else {
                    print_by_levels(root->lchild , i-1);
                    print_by_levels(root->rchild , i-1);
                    }
            }
    }
     Node* getRoot(){ return root; }
     
    int recursive_count(Node * temp) {
        if(temp == NULL)
            return 0;
        else  
            //use it to count degree 2
            //if(temp->lchild && temp ->rchild)
                return recursive_count(temp->lchild) + recursive_count(temp->rchild) +1;
                //else recursive_count(temp->lchild) + recursive_count(temp->rchild) 
    }
    
        int fun(Node * temp) {
         if(temp == NULL)
             return 0;
             else {
                 if(temp->lchild== NULL && temp->rchild ==NULL)
                     return fun(temp->lchild) + fun(temp->rchild) + 1;
                     else 
                         return fun(temp->lchild) + fun(temp->rchild) ;
             }
 
     }
    
};

int main()
{
    Tree t;
    t.CreateTree();
    cout<<t.hight(t.getRoot())<<endl;
}
