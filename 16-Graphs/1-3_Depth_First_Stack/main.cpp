#include <iostream>
#include <stack>
using namespace std;

void DFS(int v,int arr[][8], int n) {
    stack<int>s;
    int visiting[n]{0};
    visiting[v]=1;
    s.push(0);//we need to add any thing in the stack to loop inside the array based on the stack is not empty;
    cout<<v<<" , ";
    int i=1;
    while(!s.empty()) {
        while(i < n) {
            if(arr[v][i]==1 && visiting[i]==0) {
                s.push(v);
                visiting[i]=1;
                cout<<i<<" , ";
                v=i;
                i=1;
            }else 
                i++;
        }
         //so v=3+1 will be 4 and get x 2 from the stack and go to explrore  the remain of 2 so x=2 v=4 
        v=s.top();
        s.pop();
        if(v==0) {
            cout<<"break"<<endl;
            break;
            
        }
        i=v+1;//means if x is 3 means it has been called coz of 2 >>x 2 v3 so 3 has not verticies to explore so return to 2

        
    }
}
int main()
{
	 int A[8][8] = {{0, 0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 1, 1, 1, 0, 0, 0},
                   {0, 1, 0, 1, 0, 0, 0, 0},
                   {0, 1, 1, 0, 1, 1, 0, 0},
                   {0, 1, 0, 1, 0, 1, 0, 0},
                   {0, 0, 0, 1, 1, 0, 1, 1},
                   {0, 0, 0, 0, 0, 1, 0, 0},
                   {0, 0, 0, 0, 0, 1, 0, 0}};
 
   
    DFS(1, A, 8);
    cout << endl;
  
}
