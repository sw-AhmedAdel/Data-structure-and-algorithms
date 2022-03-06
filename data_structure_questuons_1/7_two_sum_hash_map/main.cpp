#include <iostream>
#include <unordered_map>
using namespace std;
#include <vector>
//time and space o(n)
//here i =3 so array[i] = 9 see in the map if value here or not ? it is not here so
// in else 11-9 =2 insert 2 and the index which is 3
//i++ so i=4 which is array[i]=2; so check in the map is array[i] here yes it is here so get the value which is map[array[i] = number if index 3
//and the i which is index 4

vector<int> get_tow_pairs ( vector<int> &array  , int target) {
    unordered_map<int , int> maps;
    for(int i=0 ; i<array.size() ; i++) {
        if(maps.find(array[i]) != maps.end()) { // here check if the key here or not which is the array[i]
           int current_value = maps[array[i]]; 
            return vector<int> {current_value , i};
        }    else {
                int value_to_find =  target - array[i];
                maps[value_to_find]=i;
            }
    }
    return {};
}

int main()
{
	   vector<int> array{1,3,7,9,2};
       vector<int> vec = get_tow_pairs(array , 11);
       for(auto i :vec)
           cout<<i<<" ";
        cout<<endl;
          
     
}
