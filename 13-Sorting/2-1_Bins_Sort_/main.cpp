#include <iostream>
using namespace std;

//bin bucket use linked list it is like counting sort element but depeond on the largest element so
// we will have a temp array will be sized as the larges element in the main array but we can use shell algo to make it more efficitnet

void print(int arr[] , int size) {
    for(int i=0 ;i<size ; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}


int get_max(int arr[] , int size) {
    int max=arr[0];
    for(int i=0;i<size ;i++) {
        if(arr[i] > max)
            max=arr[i];
    }
    return max;
}

class node{
public:
    int data;
    node *next;
};


void insert(node ** headLinkedList , int x) {
    //  0    1    2
    //[head,head,head] each head is pointer to linked list has data 
    //if the head is null so we make the head
    //if the head is not null so we loop till we get the > next is null and put newnode in the next of head
    node *new_node=new node;
    new_node->data=x;
    new_node->next=NULL;
    if(headLinkedList[x] == NULL)
        headLinkedList[x]=new_node ;// here we create the head using the value in the array if value is 6 so in index 6 in node**bins
        //which is array pointers type lined list in index 6 we create head of linked list
    else {
        node *temp=headLinkedList[x];//take the head to put the other value in it's next
        while(temp->next != NULL) {
            temp=temp->next;
        }
        temp->next=new_node;
    }
}

int delete_(node ** headLinkedList, int x) {
    node *temp=headLinkedList[x];//take the value of head
    headLinkedList[x]=headLinkedList[x]->next;//after taking the head go to the next node and make it as a head
    int xx=temp->data;
    temp->next=NULL;
    delete temp;
    return xx;
    
}

void BinSort(int arr[], int size) {
     int max=get_max(arr,size);
     max=max+1;
     node **bins=new node*[max];//here we created an array the all index in it are pointers to linked list which the index head points to linked list
                // new node * it means * the all index will be pointer
     for(int i=0 ;i< max ; i++)
         bins[i]=nullptr;
     for(int i=0;i<size ;i++)
         insert(bins,arr[i]); // send bins to go to index 6 and make the head and if 6 repeated so go to index 6 and add 6 as linked list and
         //make head attached to it
    int i=0,j=0;
    while(i<max) {
       while(bins[i]!=nullptr) {
             arr[j++]=delete_(bins,i);
        } i++;
    }
    delete []bins;
    
}

int main()
{
	 int arr[] = {6,8,3,10,15,6,9,12,6,3 };
     int size = sizeof(arr)/sizeof(arr[0]);
     print(arr,size);
     BinSort(arr,size);
     print(arr,size);
     
}
