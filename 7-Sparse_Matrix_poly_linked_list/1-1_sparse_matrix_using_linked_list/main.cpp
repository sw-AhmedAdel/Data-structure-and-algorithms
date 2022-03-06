#include <iostream>
using namespace std;

class node {
    int colum;
    int value;
    node * next;
public:
node * p;
    node *temp, * new_node;
     
    void create_sparse() {
        int m ,   n;
        cout<<"enter the size of array"<<endl;
        cin>> m >> n;
        node *arr[m];
        for(int i=0 ; i<m ; i++) {
            int size;
            cout<<"enter the size of linked list"<<endl;
            cin >> size;
            arr[i]=new node[size];
            arr[i]=NULL;
            for(int c=0 ; c<size ; c++) {
            new_node=new node;
            cout<<"enter colum"<<endl; 
            cin>>new_node->colum;
            cout<<"enter the value number"<<endl;
            cin>>new_node->value;
            new_node->next=0;
            if(arr[i]==NULL)
                arr[i]=temp=new_node;
                else {
                    temp->next=new_node;
                    temp=new_node;
                }
            }
                
        }
        cout<<"_____"<<endl;
        for(int i=0;i<m ; i++) {
            p=arr[i];
            for(int j=0 ; j<n;j++){
                if(p && p->colum == j) {
                    cout<<p->value<<" ";
                    p=p->next;
                }else 
                    cout<<"0 ";
            }
            cout<<endl;
        }
        
 
    }
   
     
};

int main()
{
 node n;
 n.create_sparse();
  }
