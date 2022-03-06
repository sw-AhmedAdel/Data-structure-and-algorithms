#include <iostream>
using namespace std;

class queues {
private:
    int front=-1;
    int rear=-1;
    int size;
    int *q;
public:
queues (int s) : size{s} {
    q=new int[size];
}
int get_num() {
    int x;
    cout<<"enter the x"<<endl;
    cin >> x;
    return x;
}
 bool empty() {
         if(rear==-1 && front ==-1)
             return true;
             else 
                 return false;
     }
     bool full(){
         if((rear+1) % size == front)
             return true;
             else 
                 return false;
     }
     void enqueue() {
         if(full()){
             cout<<"full"<<endl;
         }else if(front ==-1 && rear ==-1) {
           front=rear=0;
           q[rear]=get_num();
     }else {
         rear=(rear+1) % size;
         q[rear]=get_num();
     }
     }
     void dequeue () {
         if(empty()) {
             cout<<"empty"<<endl;
         }
         else if(front == rear ) {
             front=rear=-1;
             cout<<"deleted last element"<<endl;
         }else {
             cout<<"deleted "<<q[front]<<endl;
             front=(front+1) %size;
          }
     }
     void display(){
         int i=front;
         do {
             cout<<q[i]<<endl;
             i=(i+1 ) % size;
         }while(i!= rear+1);
     
   /*   int i =front;
    while(i!= rear) {
            cout<<q[i]<<endl;
             i=(i+1 ) % size;
     }
     cout<<q[i]<<endl;

*/
     }
 
};
int main()
{
	 queues q(5);
     int c;
     do {
         cout<<"1 insert"<<endl;
         cout<<"2- delete"<<endl;
         cout<<"3 display"<<endl;
         cin >> c;
         switch(c) {
             case 1:
             q.enqueue();
             break;
             case 2:
             q.dequeue();
             break;
             case 3:
             q.display();
             break;
             case 0:
             cout<<"exit"<<endl;
             break;
             default:
             cout<<"error try again"<<endl;
             cin >> c;
         }
     }while(c!= 0);
     
}
