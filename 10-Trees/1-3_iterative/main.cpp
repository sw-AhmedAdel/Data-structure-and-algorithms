
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
     void Preorder(Node* p) {
          stack<Node *> nodes;
          while(p!= NULL || !nodes.empty()) {
              if(p!=NULL) {
                  cout<<p->data<<" ";
                  nodes.push(p);
                  p=p->lchild;
              }
              else {
                  p=nodes.top();
                  nodes.pop();
                  p=p->rchild;
              }
          }
     }
      void Inorder(Node* p) {
          stack<Node *> nodes;
          while(p!= NULL || !nodes.empty()) {
              if(p!=NULL) {
                  nodes.push(p);
                  p=p->lchild;
              }
              else {
                  p=nodes.top();
                  nodes.pop();
                  cout<<p->data<<" ";
                  p=p->rchild;
              }
          }
     }
    void Postorder(Node* p) {
    stack<long int> stk;
    long int temp;
    while (p != nullptr || ! stk.empty()){
        if (p != nullptr){
            stk.push((long int)p);
            p = p->lchild;
        } else {
            temp = stk.top();
            stk.pop();
            if (temp > 0){//if the node is positive >0 it means i will go to the right child
                stk.push(-temp);//but push it again but negative 
                //why coz defination if it positive go to right if it is negatve print 
                p = ((Node*)temp)->rchild;
            } else {
                cout << ((Node*)(-1 * temp))->data << " " << flush;
                p = nullptr;
            }
        }
    }
    cout << endl;
}  
    void Levelorder(Node *p) {
    Queue q (25);
    cout << p->data << ", " << flush;
    q.enqueue(p);
    while (! q.isEmpty() ){
        p = q.dequeue(); 
        if (p->lchild){
            cout << p->lchild->data << ", " << flush;
            q.enqueue(p->lchild);
        }
 
        if (p->rchild){
            cout << p->rchild->data << ", " << flush;
            q.enqueue(p->rchild);
        }
    }
}
     Node* getRoot(){ return root; }
    
};

int main()
{
    Tree t;
    t.CreateTree();
    cout << "Levelorder: " <<endl;
    t.Levelorder(t.getRoot());
    cout << endl;
  
}
