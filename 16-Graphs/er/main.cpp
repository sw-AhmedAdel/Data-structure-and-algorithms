#include <iostream>
#define size 5
#define I 32767
using namespace std;

void  PrintMST (int arr[2][size-2],int cost[size][size]) {
    cout << "\nMinimum Spanning Tree Edges (w/ cost)\n" << endl;
    int sum=0;
    for(int i=0 ; i<size-2 ; i++) {//size-2 coz in arr they from  0 to 5 and has the smallest edges
    int c=cost[arr[0][i]] [arr[1][i]];
    cout<<"["<<arr[0][i]<<"]"<<"-------"<<"["<<arr[1][i]<<"]"<<"  cost is "<<c<<endl;
    sum+=c;
    }
    cout<<endl;
    cout<<"total min cost "<<sum<<endl;
}


void PrimsMST(int cost[size][size], int vertices) {
    int arr[2][size-2];
    int tracking[size];
    int u,v;
    int min=I;
    for(int i=1; i<size;i++) {
        tracking[i]=I;
        for(int j=i; j<size ;j++) {
            if(cost[i][j] < min) {
                u=i, v=j, min=cost[i][j];
            }
        }
    }
    arr[0][0]=u;
    arr[1][0]=v;
    tracking[u]=tracking[v]=0;
    //here i get the min edg and put it in the arr for gettig edges for spanning tree
    //next
    for(int i=1 ; i<size ;i++) {
        if(tracking[i]!=0) {
            if(cost[i][u] < cost[i][v])
                tracking[i]=u;
                else 
                    tracking[i]=v;
        }
    }
    for(int i=1 ;i< vertices-1 ; i++) {
        int k;
        int min=I;
        for(int j=1 ; j<size; j++) {
            if(tracking[j]!=0) {
                if(cost[j][tracking[j]] < min) {
                    k=j;
                    min=cost[j][tracking[j]];
                }
            }
        }
        
        arr[0][i]=k;
        arr[1][i]=tracking[k];
        tracking[k]=0;
        
        for(int i=1; i<size;i++) {
            if(tracking[i]!=0) {
                if(cost[i][k] < cost[i][tracking[i]]) {
                    tracking[i]=k;
                }
            }
        }
    }    PrintMST (arr,cost);    


 }



int main(){
     int cost [size][size] {
            {I,I, I, I, I},
            {I,I, 6, I, 3},
            {I,6, I, 4, I}, 
            {I,4, I, I, 2},
            {I,3, I, 2, I},        
    };
    int vertices=4;
    PrimsMST(cost,vertices);
    
}