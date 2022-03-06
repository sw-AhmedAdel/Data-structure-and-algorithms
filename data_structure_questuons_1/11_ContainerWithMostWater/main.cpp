#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;
//time is o(n*2) space is 1
//consied this is line 7 1 2 3 9 >> depends on the width and the talles line this will be the answer 
//the water from 7 >>>>9 will be so mush water 
/*int get_container_water (vector<int> array) {
    if(array.empty() || array.size() == 1)
        return 0;
        
    int max_num= INT_MIN;
    int total_container =0;
    for(int i=0 ; i<array.size()-1 ; i++) {
        int first = array[i];
        for(int j= i+1 ; j<array.size() ; j++) {
            int sec = array[j];
            total_container = min(first , sec) * abs(i - j);
            max_num= max(max_num, total_container);
        }
    }
    return max_num;
}*/
 //time is o(n) space o(1)
int get_container_water (vector<int> array) {
  int i=0;
  int j=array.size()-1;
  int max_num =INT_MIN;
  int total;
  while(i < j) {
      total = min(array[i] , array[j]) * abs(i-j);
      //why choose the min value coz 7 ,9 the water will be be stable inlike 9 7 the water will full
      //how coz once i reach 7 i will stop so the water will not full unlike 9>7 i will put the water to reach 9 but this will never
      //happen coz it is full when the water reach 7
      if(total > max_num) {
          max_num = total;
          i++;
      }else  
          j--;
  }
  return max_num;
}
 
int main()
{
	 //vector<int> array{6,8,10,2,3,9};
     	 vector<int> array{1,7,2,0,1,3};
	// vector<int> array{6,8,1,10,3,9};

     cout<<get_container_water(array)<<endl;
}
