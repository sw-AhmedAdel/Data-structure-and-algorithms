#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
 
int ge_single_element(vector<int> array) {
   sort(array.begin() , array.end());
   //if array is not sorted u need to sort it this will take nlogn
   
   //if array is already sorted this will take nlogn time and 1 space
   for(int i=1 ; i<(int)array.size()-2 ; i++) {
       if(array[i] != array[i-1] && array[i] != array[i+1])
           return array[i];
   }
   return -1;
 
}






//time is n and space is n
/*int ge_single_element(vector<int> array) {
    unordered_map<int , int > maps;
    for(int i =0 ; i<(int)array.size() ; i++) {
        if(maps.find(array[i]) == maps.end())
            maps[array[i]] =0;
        maps[array[i]]++;
    }
    auto it = maps.begin();
    while(it != maps.end()) {
        if(it->second == 1)
            return it->first;
        it++;
    }
    return -1;
}
*/
int main()
{
	 vector<int> arr{1,2,1,3,3,4,8,8,4};
     cout<<ge_single_element(arr)<<endl;
}
