#include <iostream>
using namespace std;
//first element of number 5
int get_index_of_first_elemet(int arr[], int n , int x , int i) {
    if(i==n)
        return 0;
        else {
            if(arr[i] ==x)
                return i;
                else 
                    return get_index_of_first_elemet(arr, n , x , i+1);
                    
        }
}

int main()
{
    int arr[] ={1,2,5,4,5,10,9,5,10,4,5};
     cout<<get_index_of_first_elemet(arr,11 , 5 , 0)<<endl;
}
