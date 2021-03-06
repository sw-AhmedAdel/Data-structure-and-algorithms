
#include <iostream>
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
        if(isEmpty()) {
            cout<<"empty"<<endl;
        }
        else if(front == rear) {
            x=Q[rear];
            front=rear=-1;
           
        }else {
            x= Q[front];
            front++;
            
        }
             return x;
    }
    
};

class Tree {
private:
    Node * root;
    int size;
public:
      int get_size() {
          cout<<"enter the size"<<endl;
          cin>>size;
          return size;
      }
      Tree() {
          root=nullptr;
      }
      ~Tree(){}
     void CreateTree() {
         
         Queue q(get_size());
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
         if(p) {
             cout<<p->data<<" ";
             Preorder(p->lchild);
             Preorder(p->rchild);
         }
     }
     void Postorder(Node* p) {
             if(p) {
             Postorder(p->lchild);
             Postorder(p->rchild);
             cout<<p->data<<" ";
         }
     }
     void Inorder(Node* p) {
          if(p) {
             Inorder(p->lchild);
             cout<<p->data<<"  ";
             Inorder(p->rchild);
             
         }
     }
     Node* getRoot(){ return root; }
    
};

int main()
{
    Tree t;
    t.CreateTree();
    
    cout << "Preorder: " << flush;
    t.Preorder(t.getRoot());
    cout << endl;
 
    cout << "Inorder: " << flush;
    t.Inorder(t.getRoot());
    cout << endl;
 
    cout << "Postorder: " << flush;
    t.Postorder(t.getRoot());
    cout << endl;
}
