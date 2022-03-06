#include <iostream>
using namespace std;
int global_space=10;
class node{
public:
    node * rchild;
    node * lchild;
    int data;
};

class bst{
private:
    node * root;
public:
    bst() {
        root=NULL;
    }
     void print_2d(node *root ,int space) {
        if(root==NULL)
            return;
            else {
                space=space+global_space;
                print_2d(root->rchild,space);
                cout<<endl;
                for(int i=global_space ; i<space ; i++)
                    cout<<" ";
                cout<<root->data;
                print_2d(root->lchild,space);
            }
          cout<<endl;
    }
    
    node* createBst(node * root, int x) {
        node * new_node;
        if(root==NULL) {
            new_node=new node;
            new_node->data=x;
            new_node->rchild=0;
            new_node->lchild=0;
            return new_node;
        }else {
            if(x < root->data)
                root->lchild=createBst(root->lchild , x);
                else if(x > root->data)
                    root->rchild=createBst(root->rchild,x);
        }
        return root;
    }
    
    void set_root(node * r) {root=r ;}
    node * get_root() {return root;}
 
    node * min_value(node * root) {
        node * temp=root;
        while(temp->lchild != NULL) {
            temp=temp->lchild;
        }
        return temp;
    }
    
    node * delete_(node * root ,  int val) {
        if(root==NULL)
            return root;
            else {
                if(val < root->data)
                     root->lchild=delete_(root->lchild , val);
                    else if(val > root->data)
                         root->rchild=delete_(root->rchild , val);
                        else {
                            if(root->lchild ==NULL) {
                                node * temp=root->rchild;
                                delete root;
                                return temp;
                            }
                            else if(root->rchild==NULL) {
                                node * temp=root->lchild;
                                delete root;
                                return temp;
                            }else {
                                node*temp=min_value(root->rchild);
                                root->data=temp->data;
                                 root->rchild=delete_(root->rchild , temp->data );
                            }
                        }
            }
            return root;
    }
    
};


int main()
{
	 bst t;
     int choice;  
     int x;
     node * n;
     int space{5};
     do {
     cout<<"1- implement node"<<endl;
     cout<<"2-  print_2d "<<endl;
     cout<<"3- delete"<<endl;
     cout<<"0 exit"<<endl;
     cin>> choice;
     n=new node;
     switch(choice){
         case 1:
         cout<<"enter the value"<<endl;
         cin>>x;
         n=t.createBst(t.get_root(), x);
         t.set_root(n);
         break;
         case 2:
         t.print_2d(t.get_root() , space);
         break;
         case 3:
         cout<<"enter the number to be deleted"<<endl;
         cin>>x;
         n=t.delete_(t.get_root(),x);
         t.set_root(n);
         break;
         case 0:
         cout<<"exit"<<endl;
         break;
         default:
         cout<<"error"<<endl;
         break;
     }
     
     }while(choice!= 0);
}
