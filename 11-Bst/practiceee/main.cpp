#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class BST {
public:
  int value;
  BST *left = nullptr;
  BST *right = nullptr;

  BST(int value) { this->value = value; }
};

struct treeinfo {
    int rootindex;
};
BST * buildtree(vector<int> array, int min , int max ,treeinfo & info ) ;
BST *reconstructBst(vector<int> array ) ;
BST * buildtree(vector<int> array, int min , int max ,treeinfo & info ) {
     if(info.rootindex == array.size())
         return nullptr;
     int value = array[info.rootindex];
     if(value <min || value >max)
         return nullptr;
     info.rootindex++;
     auto leftTree= buildtree(array, min , value , info);
     auto rightTree= buildtree(array , value , max , info);
     BST * root= new BST(value);
     root->left=leftTree;
     root->right=rightTree;
     return root;
}

BST *reconstructBst(vector<int> array ) {
    auto info = treeinfo{0};
     return buildtree(array , INT_MIN , INT_MAX , info);
}
void in_order(BST * root) {
    if(root!= nullptr) {
        in_order(root->left);
        cout<<root->value<<" ";
                in_order(root->right);
    }
    cout<<endl;
}
 
 int main(){
   if(2 <1 || 2 >=2 )
       cout<<"df"<<endl;
 }
