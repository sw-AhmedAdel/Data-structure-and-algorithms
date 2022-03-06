#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//trapping water
// time com is n (n * 2)
/*
int get_trapping_water ( vector<int> arr) {
     int total_water =0;
     for(int index = 0 ; index < arr.size() ; index ++) {
     int max_left=0;
     int max_right=0;
     int index_left =index;
     int index_right =index;
     while(index_left >=0) {
         max_left = max(max_left , arr[index_left]);
         index_left--;
     }
     while(index_right < arr.size()) {
         max_right = max(max_right , arr[index_right]);
         index_right++;
     }
     int current_total = min(max_right , max_left) - arr[index];
     if(current_total >=0)
         total_water+=current_total;
     }
     return total_water;
} 


int main()
{
	 vector<int> arr{0,1,0,2,1,0,3,1,0,1,2 };
     cout<<get_trapping_water(arr)<<endl;
}
*/
// reduce time to be o(n)
int get_trapping_water ( vector<int> arr) {
     int total_water =0;
     int curret_water=0;
     int max_right=0;
     int max_left=0;
     int left=0;
     int right =arr.size()-1;
     while(left < right) {
         if(arr[left] <= arr[right]) {
             max_left = max(max_left , arr[left]);
             curret_water= max_left - arr[left];
            left++;
         }
         else {
             max_right = max(max_right , arr[right]);
             curret_water = max_right - arr[right];
             right--;
         }
         
            if(curret_water >=0)
                 total_water+=curret_water;
     }
    return total_water;
} 


int main()
{
	 vector<int> arr{0,1,0,2,1,0,3,1,0,1,2 };
     //vector<int> arr{5,0,3,0,4 };
     cout<<get_trapping_water(arr)<<endl;
}
