#include <iostream>
using namespace std;



int main()
{
    int size{4};
	int coins[size]={2,3,5,10};
    int amount{15};
    int arr[size][amount+1];
    for(int i=0 ;i<size ;i++) {
        for(int c=0;c<amount+1 ;c++)
            arr[i][c]=0;
    }
    int i;
    int j;
     for(int i=0;i<1 ;i++) {
        for(int c=0 ;c <size ;c++)
            arr[c][i]=1;
    }
   
    for( i=0 ;i<size ;i++) {
        for( j=0 ;j<amount+1;j++) {
            if(coins[i] > j) {
                arr[i][j] =arr[i-1][j] ;
            }
                else {
                    arr[i][j]=arr[i-1][j] +arr[i][j-coins[i]];
                }
        }
    }
for(int i=0 ;i<size ;i++) {
        for(int c=0;c<amount+1 ;c++)
           cout<< arr[i][c]<<" ";
       cout<<endl;
    }
    

    
}
