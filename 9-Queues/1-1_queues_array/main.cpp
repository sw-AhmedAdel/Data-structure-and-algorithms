#include <iostream>
using namespace std;

class queues {
private:
    int size;
    int front =-1;
    int rear=-1;
    int * q;
public:
    queues(int s) :size{s} {
        q=new int[size];
    }
    bool empty() {
        if(front ==-1&& rear ==-1 )
            return true;
            else 
                return false;
    }
    bool full() {
        if(rear == size-1)
            return true;
            else 
                return false;
    }
    
    void enqueue() {
        if(full()){
            cout<<"is full"<<endl;
        }else if(front==-1 && rear==-1) {
             front=rear=0;
            int x;
            cout<<"enter the num"<<endl;
            cin >> x;
            q[rear]=x;
        }
            else{
            int x;
            cout<<"enter the num"<<endl;
            cin >> x;
            rear++;
            q[rear]=x;
        }
    }
    void dqueue() {
        if(empty()) {
            cout<<"empty"<<endl;
        }else if(rear == front)  {
            front=rear=-1;
        }
            
            else{
            int x;
            front++;
            x=q[front];
            cout<<"deleted "<<x<<endl;
        }
    }
    
    void display() {
        if(empty()){
            cout<<"empty"<<endl;
        }else {
            for(int i=front ; i<= rear ; i++)
                cout<<q[i]<<endl;
        }
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
             q.dqueue();
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
