#include <iostream>
using namespace std;
#include <queue>


// first get the root and insert it in the q 5
// pop it and ask for the left and right and put them in the q 8 6
//check if q is empty no ?? so pop the left 8 that i put it and ask it i want left or chiled 3 9
//and put them in the q 6 3 9
// check if q is not empty pop the right the first right  6 and ask for the left and the right if they are -1 and -1
// so pop 3 and ask for it l and r if it -1 and -1 pop 9 and ask if it -1 and -1 here q is empty
class node {
private:
    int data;
    node * r_child;
    node * l_child;
public:
    node * temp , * new_node;
    void create () {
        queue<node *> q;
        new_node=new node;
        cout<<"enter the number for root node"<<endl;
        cin >> new_node->data;
        new_node->r_child=0;
        new_node->l_child=0;
        q.push(new_node);
        while(!q.empty()) {
            temp = q.front();
            q.pop();
            int x;
            cout<<"enter the number for left child "<<endl;
            cin>>x;
            if(x != -1) {
                new_node=new node;
                new_node->r_child=0;
                new_node->l_child=0;
                new_node->data=x;
                temp->l_child=new_node;
                q.push(new_node);
            }
            cout<<"enter the number for right child "<<endl;
            cin >> x;
            if(x != -1) {
                new_node=new node;
                new_node->r_child=0;
                new_node->l_child=0;
                new_node->data=x;
                temp->r_child=new_node;
                q.push(new_node);
            }
        }
    }
};
int main()
{
 node n;
 n.create();
}
