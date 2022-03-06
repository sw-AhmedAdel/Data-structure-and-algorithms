#include <iostream>
using namespace std;
int globalspace=10;
class node {
public:
    node * rchild;
    node * lchild;
    int data;
};
class bst {
private:
    node * root ;
    int bf;
public:
 bst(){
     root=NULL;
 }
   int hight(node * root) {
      int x;
      int y;
      if(root != NULL) {
          x=hight(root->lchild);
          y=hight(root->rchild);
          if(x > y)
              return x+1;
              else 
                  return y+1;
      }else 
          return -1;
  }
  
  int get_balance_factor(node * root) {
      if(root==NULL)
          return -1;
          else {
              return (hight(root->lchild) - hight(root->rchild));
          }
  }
  node * leftRotate(node * root) {
      node * temp=root->rchild;
      node *left=temp->lchild;
      temp->lchild=root;
      root->rchild=left;
      return temp;
  }
  
  node *rightRotate(node * root) {
      node * temp=root->lchild;
      node *right=temp->rchild;
      temp->rchild=root;
      root->lchild=right;
      return temp;
  }
  
    node * createBst_recursive(node * root , node * new_node) {
      if(root==NULL) {
          return new_node;
      }else {
          if(new_node->data < root->data)
              root->lchild=createBst_recursive(root->lchild , new_node);
              else if(new_node->data > root->data)
                  root->rchild=createBst_recursive(root->rchild,new_node);
                  else if(new_node->data==root->data) {
                      cout<<"duplicates data"<<endl;
                      return root;
                  }
 
     
   }
return root;
}
    node * min_value(node * root) {
        node * temp=root;
        while(temp->lchild != NULL) {
            temp=temp->lchild;
        }
        return temp;
    }
    ///////////// delete
    node * delete_(node * root ,  int x) {
        if(root==NULL)
            return root;
               else if(x < root->data)
                    root->lchild=delete_(root->lchild , x);
                    else if(x > root->data)
                        root->rchild=delete_(root->rchild , x);
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
            bf=get_balance_factor(root);
            //left left then do right
            if(bf==2 && get_balance_factor(root->lchild) >=0)
               return rightRotate(root);
            //left right then left, right
            else if(bf==2 && get_balance_factor(root->lchild)==-1){
                root->lchild=leftRotate(root->lchild);
               return rightRotate(root);
            }
            //right right
            else if(bf==-2 && get_balance_factor(root->rchild) <=0)
              return  leftRotate(root);
            //right left then right left
            else if(bf==-2 &&get_balance_factor(root->rchild)==1) {
                root->rchild=rightRotate((root->rchild));
              return  leftRotate(root);
            
            }
            return root;
    }
void in_order(node * root) {
    if(root!= NULL) {
        in_order(root->lchild);
        cout<<root->data<<" ";
        in_order(root->rchild);
    }
}

void print_2d(node * root, int space){
    if(root!= NULL) {
    space=space+globalspace;
    print_2d(root->rchild,space);
    cout<<endl;
    for(int i=globalspace ; i<space ; i++) 
        cout<<" ";
    cout<<root->data<<" ";
    print_2d(root->lchild,space);
    }else 
        return;
  }
  void set_node(node * n) {root=n;}
  node * get_root() {return root;}
};

int main()
{
  bst t;
  int space {5};
  int choice;
  node *n;
  int x;
  node * new_node;
  do {
      cout<<"1- insert to AVL Tree"<<endl;
      cout<<"2- deleted in AVL Tree"<<endl;
      cout<<"3- print 2d "<<endl;
      cout<<"0 exit"<<endl;
      new_node=new node;
      n=new node;
      cin >> choice;
      switch(choice){
      case 1:
      cout<<"enter the value"<<endl;
      cin>>new_node->data;
      new_node->lchild=0;
      new_node->rchild=0;
      n=t.createBst_recursive(t.get_root(),new_node);
      t.set_node(n);
      break;
      case 2:
      cout<<"enter the value to be deleted"<<endl;
      cin>>x;
      n=t.delete_(t.get_root(),x);
      t.set_node(n);
      break;
      case 3:
      t.print_2d(t.get_root(),space);
      cout<<endl;
      break;
      case 0:
      cout<<"exit"<<endl;
      break;
      default:
      cout<<"error"<<endl;
      break;
      }
  }while(choice !=0);
}
