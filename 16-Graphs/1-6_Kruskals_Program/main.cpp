#include <iostream>
using namespace std;
#define I 32767  // Infinity
#define vertices 7  // 
#define edgesNumber 9  // 

int find(int s[] , int u) {
    int x = u;
    while (s[x] > 0){
        x = s[x];
    }
    return x;
}

void union_(int u , int v, int set[]) {
    if(set[u] < set[v]) {
        set[u]+=set[v];
        set[v]=u;
    }else {
        set[v]+=set[u];
        set[u]=v;
    }
}
 
void print(int arr[][vertices-1]) {
     for (int i {0}; i<vertices-1; i++){
        cout << "[" << arr[0][i] << "]-----[" << arr[1][i] << "]" << endl;
    }
}

void KruskalsMCST(int edges[][edgesNumber] ) {
    int arr[2][vertices-1];//get the 6 edges for min edges
    int track[edgesNumber]{0}; // Track edges that are included in solution they are 9 so need track to mark the edge that i get
    int set[vertices+1]={-1, -1, -1, -1, -1, -1, -1, -1};//we have 7 verties and use it to see of there is cycle or not using the v
    //if the parent of vertices are equal means it is cyle and here the index num are the vertices what inside the index is parent
    int i=0;
    while(i<vertices-1) {//why? coz 7-1=6 and 6 this is the number of min edges for Kruskals
        int min = I;
        int u {0};
        int v {0};
        int k {0};
      
     for(int j=0; j < edgesNumber ;j++) {
            if(track[j]==0 && edges[2][j] < min) {
                min=edges[2][j];
                k=j;
                u=edges[0][j];
                v=edges[1][j];
            }
        }
        track[k]=1;
        if(find( set, u) != find(set, v)) {
            cout<<find( set, u) <<"<<<<"<<find( set, v)<<endl;
            arr[0][i]=u;
            arr[1][i]=v;
            union_(find(set, u),find(set,v) , set );
            i++;//why is this scope coz if vertices parent are not eqaul means no cycle so put them in arr and increase i
        }
         
    }
    
    print(arr);
    
}

int main()
{
	 int edges[3][9] = {{ 1, 1,  2,  2, 3,  4,  4,  5,  5},
                       { 2, 6,  3,  7, 4,  5,  7,  6,  7},
                       {25, 5, 12, 10, 8, 16, 14, 20, 18}};
   
    KruskalsMCST(edges);
 
    return 0;
}
