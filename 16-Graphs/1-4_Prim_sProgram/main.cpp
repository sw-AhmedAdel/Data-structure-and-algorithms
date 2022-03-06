#include <iostream>
#define V 8
#define I 32767
using namespace std;

void PrintMST(int arr[2][V-2] , int cost[V][V]) {
    cout << "\nMinimum Spanning Tree Edges (w/ cost)\n" << endl;
    int sum=0;
    for(int i=0 ; i<V-2 ; i++) {
        int c = cost[arr[0][i]][arr[1][i]];//1 6 there cost is 5
        cout<<"["<<arr[0][i]<<"]"<<"-------"<<"["<<arr[1][i]<<"]"<<"  cost is "<<c<<endl;
        sum+=c;
    }
    cout<<endl;
    cout<<"total min cost "<<sum<<endl;
}


//v is the size of matricx which is 8 and n the size of vertices number but here n is number of vertices 
void PrimsMST (int cost[V][V] , int n) {
    int u;
    int v;
    int min=INT_MAX;
    int track[V];//here index will be the vertices and inside the index will be the vertic that is index vertice conntected to
    int arr[2][V-2]={0};//here is store the edges
    // step 1 find the min edges
    for(int i=1 ; i<V ; i++) {
        track[i]=-1;
        for(int j=i ; j<V ; j++) {//j=i this is indirectd grap so using upper array to get the min edges coz it is the same in lower array
        if(cost[i][j] < min) {
            min=cost[i][j];//the min cost
            u=i,v=j;//the min edges
           }
        }
    }
    arr[0][0]=u;
    arr[1][0]=v;
    track[u]=track[v]=0;
    
    //intilize the track array with the nearst from 1 and 6 edges 
    for(int i=1 ; i<V; i++) {
     if(track[i]!=0 ) {
        if(cost[u][i] < cost[v][i]) 
            track[i]=u;
            else 
                track[i]=v;
        }
    }
    //this is repeated steps 
    //after initlize the track now get the min enges 
    for(int i=1 ; i<n-1 ;i++) {//n-1>>n=7 -1= 6 why coz is arr we intilized the frist index and we need to intilize just 5 index so n<6
        int k;
        min=INT_MAX;
        
        for(int j=1 ; j<V ; j++) {
            if(track[j]!=0 && cost[j][track[j]] < min) 
            {
                k=j;
                min=cost[j][track[j]];
            }
        }
        //after knowing the min now update the arr with the new edges
        arr[0][i]=k;//the edg 5
        arr[1][i]=track[k];// 6 that 5 conntected to
        track[k]=0;//make 5 0
        
        //last step check the new edge which is 5 with the ohter in track array to see if there near to 5 or not
        for(int j=1 ; j<V ; j++) {
            if(track[j]!=0 && cost[k][j] < cost[j][track[j]])
                track[j]=k;
        }
    }
     
PrintMST (arr,cost);    
}


int main() {
int cost [V][V] {
            {I, I, I, I, I, I, I, I},
            {I, I, 25, I, I, I, 5, I},
            {I, 25, I, 12, I, I, I, 10},
            {I, I, 12, I, 8, I, I, I},
            {I, I, I, 8, I, 16, I, 14},
            {I, I, I, I, 16, I, 20, 18},
            {I, 5, I, I, I, 20, I, I},
            {I, I, 10, I, 14, 18, I, I},
    };
    int n = sizeof(cost[0])/sizeof(cost[0][0]) - 1;
    PrimsMST(cost, n);

}