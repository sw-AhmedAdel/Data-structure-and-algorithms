#include <iostream>
using namespace std;

class stack {
    int * arr;
    int n;
    int top=-1;
public:
    stack(int s) : n{s} {
        arr=new int[n];
    }
    void push() {
        int choice =1;
        while(choice ==1) {
            if(top ==n-1) {
                cout<<"stack is full"<<endl;
                break;
            }else {
                int num;
                cout<<"enter the number"<<endl;
                cin >> num;
                top++;
                 arr[top]=num;
            }
            cout<<"want to insert again"<<endl;
            cin >> choice;
        }
    }
    void  pop() {
        int choice =1;
        while(choice ==1) {
        if(top == -1) {
            cout<<"no nodes to be deleted"<<endl;
            break;
        }else {
            int num=arr[top--];
            cout<<"deleted "<<num<<endl;
         }
         
            cout<<"want to delete again"<<endl;
            cin >> choice;
        }
    }
    
    int peak(int pos) {
      //if the pos ==1 that will give u index number 4 the top in the stack
        if(top - pos +1 <0)//peak =5 so top =4 - 5 = -1+1 = 0 the last in the stack
        //peak = 1 so 4-1=3 +1 = 4 the top in the stack
            return -1;
            else {
            
                return arr[top - pos +1 ];
            }
    }
    void display() {
        for(int i=top ; i>=0 ; i--)
            cout<<arr[i]<<endl;
    }
    bool is_empty() {
        if(top==-1)
             return true;
            else 
                 return false;
    }
    bool is_full(){
        if(top == n-1)
            return true;
            else 
                return false;
    }
};

int main()
{
	stack s(5);
    s.push();
    s.display();
    cout<<"_____"<<endl;
   // s.pop();
    cout<<"_______"<<endl;
    cout<<s.peak(5)<<endl;// means the top 
    /* pos 1 = index 4
     * pos 2 = index 3 
     * pos 3 = index 2
     * pos 4 = index 1 
     * pos 5 = index 0*/
     
 }
