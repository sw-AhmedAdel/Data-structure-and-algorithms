#include <iostream>
using namespace std;
const int size{5};
int stack_1[size];
int stack_2[size];
int top1=-1;
int top2=-1;
int counter=0;
void push1(int x) {
    top1++;
    stack_1[top1]=x;
}
void push2( int x) {
    top2++;
    stack_2[top2]=x;
}
int pop1 () {
    return stack_1[top1--];
}
int pop2() {
    return stack_2[top2--];
}
bool full() {
    if(top1==size-1)
        return true;
        else 
            return false;
}
void enqueue () {
    if(full())
        cout<<"full"<<endl;
        else {
            int x;
            cout<<"enter the x"<<endl;
            cin >> x;
            counter++;
            push1(x);
        }
}

bool empty() {
    if(top1==-1)
        return true;
        else 
            return false;
}
void dequeue () {
    if(empty() ) {
        cout<<"empty"<<endl;
    }else {
        int num;
        for(int i=0 ; i<counter ; i++) {
            num=pop1();
            push2(num);
        }
        num=pop2();
        cout<<"deleted "<<num<<endl;
        counter--;
        for(int i=0 ; i<counter ; i++) {
            num=pop2();
            push1(num);
        }
    }
}
void display() {
    for(int i=0 ; i<=top1; i++)
        cout<<stack_1[i]<<endl;
}
int main()
{
	 int choice;
     do{
         bool is_true{false};
         cout<<"1- enqueuee"<<endl;
         cout<<"2- dequeue"<<endl;
         cout<<"3- peek"<<endl;
         cout<<"4- display"<<endl;
         cout<<"5- quit"<<endl;
         cout<<"enter the choice between 1 to 5"<<endl;
         cin >> choice;
         while(!is_true) {
         switch(choice){
             case 1:
             enqueue();
             is_true=true;
             break;
             case 2:
             dequeue();
             is_true=true;
             break;
             case 3:
             display();
             is_true=true;
             break;
             case 4:
             cout<<"quit"<<endl;
             is_true=true;
             break;
             default:
             cout<<"invalied "<<endl;
             cin >> choice;
             is_true=false;
             
         }
     }
     }while(choice != 5);
}
