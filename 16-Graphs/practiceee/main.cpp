#include <iostream>
#define size 8
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



void PrimsMST(int cost[size][size], int n) {
    int u;
    int v;
    int tracking[8];//why 8 coz vertices from 1 to 7 but i need an array represent from 1 to 7 so i made it as 8
    int arr[2][size-2];
    int min {I};
    //here get the smallest edge
    for(int i=1 ; i<size ; i++) {
        tracking[i]=I;// INTILIZE TRACK WITH I;why coz insid tracks index the number of vertices like 1 will be store in index 2
        //means insed 2 connected with 1 so store number so sotre the largest number which is i something begger than the all vertices 
        for(int j=i ; j<size;j++) {
            if(cost[i][j] < min) {
                min=cost[i][j];
                u=i,v=j;
            }
        }
    }
    //step 1 intilized it in arr which will have the lowest edges and the 
    //track array will have the vertices which is the number of v expcet 0
    arr[0][0]=u;
    arr[1][0]=v;
    tracking[u]=tracking[v]=0;
    
    //step 2 intilized the track array the it's index are the number of v
    //intlized it with the nearest to edge 1 or 6
    for(int i=1 ; i<size ; i++) {
        if(tracking[i]!=0) {
            if(cost[i][u] < cost[i][v])
                tracking[i]=u;
                else 
                    tracking[i]=v;
        }
    }
    //step 3 after intilized the track array now
   
    
    for(int i=1 ;i<n-1 ; i++) {
        int k;
        min=I;
        //get the min edge to  1 or 6 
        for(int j=1 ; j<size ;j++) {
            if(tracking[j]!=0) {
                if(cost[j][tracking[j]] < min) {
                    k=j;
                    min=cost[j][tracking[j]];
                }
            }
        }
         // will be 5 so put 5 in the array for min edges and update track 5=0
         arr[0][i]=k;
         arr[1][i]=tracking[k];
         tracking[k]=0;
         
    //and compare 5 with track to see if the remain v are near to 5 or 1 or 6 and update the track with that
    //repeat the all steps
    for(int i=1;i<size;i++) {
        if(tracking[i]!=0) {
            if(cost[i][k] < cost[i][tracking[i]])
                tracking[i]=k;
        }
      }
    }
    PrintMST (arr,cost);    

}
 
int main() {
 
    int cost [size][size] {
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
 
    return 0;
}