#include <iostream>
#include <string>
using namespace std;


class deques {
int front=-1;
int real=-1;
int size ;
int  * deque;
public:
deques(int s) : size{s} {
    deque=new int[size];
}
bool empty(){
    if(front==-1 && real== -1 )
        return true;
        else
            return false;
}
bool full() {
    if((front ==0&& real ==size-1)  || ( real+1 ==front)  )
        return true;
        else
            return false;
}

void enqueue_front() {
    if(  full() )
        cout<<"deque is full"<<endl;
        else if(front==-1 && real ==-1) {
            front=real=0;
            int x;
            cout<<"enter the x"<<endl;
            cin >> x;
            deque[front]=x;
        }
        else if(front==0) {
            front=size-1;
            int x;
            cout<<"enter the x"<<endl;
            cin >> x;
            deque[front]=x;
        }else {
            front--;
            int x;
            cout<<"enter the x"<<endl;
            cin >> x;
            deque[front]=x;
        }
}
void enqueue_real() {
    if(full() )
        cout<<"full"<<endl;
        else if(front==-1 && real==-1)
        {
            front=real=0;
            int x;
            cout<<"enter the x"<<endl;
            cin >> x;
            deque[real]=x;
        }
        else if(real==size-1) {
            real=0;
            int x;
            cout<<"enter the x"<<endl;
            cin >> x;
            deque[real]=x;
        }else {
            real ++;
            int x;
            cout<<"enter the x"<<endl;
            cin >> x;
            deque[real]=x;
        }
}
void dequeue_front () {
    if(empty())
        cout<<"empty"<<endl;
        else if(front ==real) {
            front=real =-1;
            cout<<"deleting last num"<<endl;
        }else if(front==size-1) {
            cout<<"deleting "<<deque[front]<<endl;
            front=0;
        }else {
            cout<<"deleting "<<deque[front]<<endl;
            front++;
        }
}

void dequeue_real() {
    if(empty()) {
        cout<<"empty"<<endl;
    }
    else if(front==real) {
            front=real =-1;
            cout<<"deleting last num" <<endl;
    }
    else if(real==0) {
        real=size-1;
        cout<<"deleting  "<<deque[real] <<endl;
    }else {
        cout<<"deleting  "<< deque[real]<< endl;
        real--;
    }
}
void display(){
    if(front ==-1 && real ==-1)
        cout<<"empty"<<endl;
        else {
            int i=front;
            while(i != real) {
                cout<<deque[i]<<" ";
                i=(i+1) % size;
            }
            cout<<deque[i]<<endl;
        }
}

};

int main()
{
    deques d(5);
	 int choice;
     do{
         bool is_true{false};
         cout<<"1- enqueuee front"<<endl;
         cout<<"2- enqueuee real "<<endl;
         cout<<"3- dequeuee front"<<endl;
         cout<<"4- dequeuee real"<<endl;
         cout<<"5- display"<<endl;
         cout<<"6-quit"<<endl;
         cout<<"enter the choice between 1 to 5"<<endl;
         cin >> choice;
         while(!is_true) {
         switch(choice){
             case 1:
             d.enqueue_front ();
             is_true=true;
             break;
             case 2:
             d.enqueue_real();
             is_true=true;
             break;
             case 3:
             d.dequeue_front();
             is_true=true;
             break;
             case 4:
             d.dequeue_real();
             is_true=true;
             break;
             case 5:
             d.display();
             is_true=true;
             break;
             case 6:
             cout<<"quit"<<endl;
             is_true=true;
             break;
             default:
             cout<<"invalied "<<endl;
             cin >> choice;
             is_true=false;
             
         }
     }
     }while(choice != 6);
}