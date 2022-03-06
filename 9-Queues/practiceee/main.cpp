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
    if((front ==0&& real ==size-1)  || ( front== real+1)  )
        return true;
        else
            return false;
}
int get_num() {
    int x;
    cout<<"etner the num"<<endl;
    cin >> x;
    return x;
}

void enqueue_front() {
   if(full()) { // front =0 rear = size-1 || fron = rear + 1
       cout<<"full"<<endl;
   }
   else if(front ==-1 && real ==-1) {
       front=real=0;
       deque[real]=get_num();
   }
   else if(front==0) {
       front=size-1;
       deque[front]=get_num();
   }else {
       front--;
       deque[front]=get_num();
   }
   
}
void enqueue_real() {
     if(full())  
         cout<<"full"<<endl;
     else if(front==-1 && real ==-1) {
          front=real=0;
          deque[real]=get_num();
     }
     else if(real==size-1) {
         real=0;
         deque[real]=get_num();
     }else {
         real++;
        deque[real]=get_num();
     }
}
void dequeue_front () {
     if(empty()) {
       cout<<"empty"<<endl;
     }
     else if(front == real) {
         cout<<"deleted last node"<<endl;
         front=real=-1;
     }else if(front==size-1) {
         cout<<"deleted "<<deque[front]<<endl;
         front=0;
     }
     else {
         cout<<"deleted "<<deque[front]<<endl;
         front++;
     }
}

void dequeue_real() {
     if(empty()) {
       cout<<"empty"<<endl;
     }
     else if(front == real) {
         cout<<"deleted last node"<<endl;
         front=real=-1;
     }else if(real==0) {
         cout<<"deleted "<<deque[real]<<endl;
         real=size-1;
     }else {
         cout<<"deleted "<<deque[real]<<endl;
         real--;
     }
}
void display(){
     int i=front;
     do {
         cout<<deque[i]<<endl;
         i=(i+1) % size;
     }while(i != real+1);
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