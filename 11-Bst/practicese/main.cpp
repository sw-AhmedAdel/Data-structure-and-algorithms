#include <iostream>
#include <stack>
using namespace std;
 //generating node from pre order
 //if generating from post order do it from the right to the left
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
      bst(){
          root=NULL;
      }
      void generating_bst(int arr[] , int n) {
      int i=0;
      root=new node;
      root->data=arr[i++];
      root->lchild=0;
      root->rchild=0;
      node * temp=root;
      node *new_node;
      stack<node *> s;
      while(i < n ) {
       if(arr[i] < temp->data) {
           new_node=new node;
           new_node->data=arr[i++];
           new_node->lchild=0;
           new_node->rchild=0;
           temp->lchild=new_node;
           s.push(temp);
           temp=new_node;
       }else if(arr[i] > temp->data && arr[i] < (s.empty() ? 32767 : s.top()->data)){         
           new_node=new node;
           new_node->data=arr[i++];
           new_node->lchild=0;
           new_node->rchild=0;
           temp->rchild=new_node;
           temp=new_node;
       }else 
       {
           temp =s.top();
           s.pop();
       }   
      }
}
    node * get_root() {return root;}
  void in_order(node * t) {
        if(t!=NULL) {
            in_order(t->lchild);
            cout<<t->data<<" ";
            in_order(t->rchild);
        }else 
            return ;
    }
};

int main()
{
     int size{9};
	 int arr[size]={30,20,10,15,25,40,50,45 , 60};
     bst t;
     t.generating_bst(arr,size);
     t.in_order(t.get_root());
}
