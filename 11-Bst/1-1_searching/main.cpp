#include <iostream>
using namespace std;

class node {
public:
    node * rchild;
    node * lchild;
    int data;
};

class bst {
private:
    node * root ;
public:
 bst(){
     root=NULL;
 }
  void createBst() {
           node* new_node=new node;
           cout<<"enter the value"<<endl;
           cin>>new_node->data;
           new_node->lchild=0;
           new_node->rchild=0;
           if(root==NULL) {
               root=new_node;
           }
           else {
             node* temp=root;
                while(temp != NULL) {
                    if(temp->data ==new_node->data) {
                        cout<<"this value alredy exits please try again !!"<<endl;
                        return;
                    }
                    else if((new_node->data < temp->data) &&  temp->lchild==NULL) {
                        cout<<"new node has been set up in the left "<<endl;
                        temp->lchild=new_node;
                        return;
                    }
                    else if(new_node->data < temp->data) {
                        temp=temp->lchild;
                    }
                    else if((new_node->data > temp->data) && (temp->rchild==NULL)) {
                        cout<<"new node has been set up in the right"<<endl;
                        temp->rchild=new_node;
                        return;
                    }else 
                        temp=temp->rchild;
                }
        
       }
  }
  
  node * createBst_recursive(node * root , int x) {
      node * new_node;
      if(root==NULL) {
          new_node=new node;
          new_node->data=x;
          new_node->lchild=0;
          new_node->rchild=0;
          return new_node;
      }else {
          if(x < root->data)
              root->lchild=createBst_recursive(root->lchild , x);
              else if(x > root->data)
                  root->rchild=createBst_recursive(root->rchild,x);
      }
      return root;
  }

    node * get_root(){
        return root;
    }
    
    node * recurcive_search(node * root , int x) {
        if(root==NULL)
            return NULL;
            else {
            if(root->data == x)
                return root;
               else if(x > root->data)
                    return recurcive_search(root->rchild , x);
                        else 
                            return recurcive_search(root->lchild , x);
                }
          }
    
    node * loop_search(int x) {
        if(root==NULL)
            return NULL;
            else {
                node* temp=root;
                while(temp != NULL) {
                    if(temp->data ==x)
                        return temp;
                        else if(x < temp->data)
                            temp=temp->lchild;
                            else 
                                temp=temp->rchild;
                }
                
            }
            return NULL;
    }
    bool is_empty() {
        if(root==NULL)
            return true;
            else 
                return false;
    } 
    
    void insert( node * root ,int x) {
        node * temp;
        while(root!= NULL) {
            temp=root;
            if(root->data==x)
                return ;
                else if(x > root->data)
                    root=root->rchild;
                    else 
                        root=root->lchild;
        }            
        node*new_node= new node;
        new_node->data=x;
        new_node->lchild=0;
        new_node->rchild=0;
        if(new_node->data < temp->data)
           temp->lchild=new_node;
           else 
               temp->rchild=new_node;
    }
     
    void in_order(node * t) {
        if(t!=NULL) {
            in_order(t->lchild);
            cout<<t->data<<" ";
            in_order(t->rchild);
        }else 
            return ;
    }
    void set_root(node * r) {
        root =r;
    }
    node * min_value() {
        node * temp=root;
        while(temp->lchild != NULL) {
            temp=temp->lchild;
        }
        return temp;
    }
};

int main()
{
  int x;
  bst b;
  int choice;
  do {
      cout<<"1- implement node"<<endl;
      cout<<"2- search using recurcive_search "<<endl;
      cout<<"3- search using loops  "<<endl;
      cout<<"4- insert a new node"<<endl;
      cout<<"5- inorder "<<endl;
      cout<<"6- impement nodes using recursion"<<endl;
      cout<<"0- exit"<<endl;
      cin>> choice;
      node *n=new node;
      switch(choice) {
          case 1:
          b.createBst();
          break;
          case 2:
          cout<<"enter the key"<<endl;
          cin >> x;
          n= b.recurcive_search(b.get_root(),x);
          if(n== NULL)
                  cout<<"is not found"<<endl;
              else 
                  cout<<"number is found "<<n->data<<endl;
         break;
         case 3:
         cout<<"enter the key"<<endl;
         cin>>x;
         n=b.loop_search(x);
         if(n== NULL)
                  cout<<"is not found"<<endl;
              else 
                  cout<<"number is found "<<n->data<<endl;
         break;
         case 4:
         cout<<"insert new node"<<endl;
         cin >>x;
         b.insert(b.get_root() , x);
         break;
         case 5:
         b.in_order(b.get_root());
         cout<<"______________"<<endl;
         break;
         case 6:
         cout<<"enter the node"<<endl;
         cin >>x;
         n=b.createBst_recursive(b.get_root() ,x);
         b.set_root(n);
         break;
         case 0 :
         cout<<"exit"<<endl;
         break;
         default:
         cout<<"error"<<endl;
      }
  }while(choice != 0);
 
}
