#include <iostream>
#include <vector>
using namespace std;

bool is_jumb_game_true(vector<int> array) {
   
    int i=array.size()-2;
    int next= array.size()-1;
    int current;
    while(i >=0 ) {
        current = i + array[i];
        if(current >= next)
            next=i;
    i--;
    }
    return next==0;
}

int main()
{                  //0 1 2 3 4  
	 vector<int> arr{2,3,1,1,4};
     cout<<is_jumb_game_true(arr)<<endl;
}
