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
       int choice=1;
       while(choice ==1) {
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
                        break;
                    }
                    else if(new_node->data < temp->data) {
                        temp=temp->lchild;
                    }
                    else if((new_node->data > temp->data) && (temp->rchild==NULL)) {
                        cout<<"new node has been set up in the right"<<endl;
                        temp->rchild=new_node;
                        break;
                    }else 
                        temp=temp->rchild;
                }
           }
           cout<<"want to insert another data"<<endl;
           cin>> choice;
       }
  }

     int get_hight(tree_node * root) {
        if(root==NULL)
            return -1;
            else {
                int l_hight=get_hight(root->left);
                int r_hight=get_hight(root->right);
                if(l_hight > r_hight)
                    return l_hight+1;
                    else 
                        return r_hight+1;
            }
    }
    node * get_root(){
        return root;
    }
 void in_order(node *root) {
        if(root==NULL)
            return;
            else {
                in_order(root->lchild);
                cout<<root->data<<" ";
                in_order(root->rchild);
            }
    }
    void pre_order(node *root) {
        if(root==NULL)
           return;
           else {
               cout<<root->data<<" ";
               pre_order(root->lchild);
               pre_order(root->rchild);
           }
    }
    void post_order(node *root) {
        if(root==NULL)
            return;
            else {
                post_order(root->lchild);
                post_order(root->rchild);
                cout<<root->data<<" ";
            }
    }
    
    void print(node *root) {
        if(is_empty())
            cout<<"empty"<<endl;
            else {
                cout<<"in order :";
                in_order(root);
                cout<<endl;
                cout<<"pre order :";
                pre_order(root);
                cout<<endl;
                cout<<"post order :";
                post_order(root);
                cout<<endl;
            }
    }
    bool is_empty(){
        if(root==NULL)
            return true;
            else 
                return false;
    }
};

int main()
{
	 bst b;
     b.createBst();
     b.print(b.get_root());
 
}
