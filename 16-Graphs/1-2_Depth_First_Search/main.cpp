#include <iostream>
using namespace std;


void DFS(int v, int arr[][8],int n )
{
    static int visiting [8]{0};
    if(visiting[v]==0) {//when get the v mark it as 1 and start to explore it using for loop to get another v and call it using stack 
    //and repeat
        cout<<v<<" , ";
        visiting[v]=1;
    for(int i=1 ;i<n;i++) {
        if(arr[v][i]==1 && visiting[i]==0 ){
            DFS(i,arr,n);
        }
    }
}

      
}

int main()
{              //0  1  2  3  4  5  6  7
    int arr[8][8]={{0,0, 0, 0, 0, 0, 0, 0},
                   {0, 0, 1, 1, 1, 0, 0, 0},
                   {0, 1, 0, 1, 0, 0, 0, 0},
                   {0, 1, 1, 0, 1, 1, 0, 0},
                   {0, 1, 0, 1, 0, 1, 0, 0},
                   {0, 0, 0, 1, 1, 0, 1, 1},
                   {0, 0, 0, 0, 0, 1, 0, 0},
                   {0, 0, 0, 0, 0, 1, 0, 0}};
                   
    cout << "Vertex: 1 -> " << flush;
    DFS(1 ,arr, 8);//send 8 as number of v but they are 7 but send 8 to loop throw them

 
}
