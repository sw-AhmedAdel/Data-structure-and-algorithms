#include <iostream>
#include <queue>
using namespace std;
 
void BFS(int v, int arr[][8], int n ){
    queue<int>q;
    int visiting[n]{0};
    visiting[v]=1;
    cout<<v<<" , ";
    q.push(v);
    int temp;
    while(!q.empty()) {
        temp= q.front();
        q.pop();
        for(int i=1 ;i<n; i++) {
            if(arr[temp][i]==1 && visiting[i]==0 ) {
                cout<<i<<" , ";
                visiting[i]=1;
                q.push(i);
            }
        }
    }
    cout<<endl;
}
 
int main (){
                 //  0  1  2  3  4  5  6  7
int arr[8][8]={{0, 0, 0, 0, 0, 0, 0, 0},
                     {0, 0, 1, 1, 1, 0, 0, 0},
                     {0, 1, 0, 1, 0, 0, 0, 0},
                     {0, 1, 1, 0, 1, 1, 0, 0},
                     {0, 1, 0, 1, 0, 1, 0, 0},
                     {0, 0, 0, 1, 1, 0, 1, 1},
                     {0, 0, 0, 0, 0, 1, 0, 0},
                     {0, 0, 0, 0, 0, 1, 0, 0}};
 
    cout << "Vertex: 1 -> " << flush;
    BFS(1, arr, 8);//send 8 as number of v but they are 7 but send 8 to loop throw them
 
    cout << "Vertex: 4 -> " << flush;
    BFS(4, arr, 8);
 
 
    return 0;
}