#include <iostream>
#include <vector>
using namespace std;


int get_first_last_index(vector<int> array , int target , bool flag) {
    int s=0;
    int e=array.size()-1;
    int temp =-1;
    while(s <=e) {
        int mid = (s+e) /2;
        if(array[mid] == target) {
            if(flag == true) {
                temp = mid;
                e= mid-1;
            }else {
                temp=mid;
                s=mid+1;
            }
        }
        else if(target < array[mid])
            e=mid-1;
            else 
                s=mid+1;
    }
    return temp;
}

vector<int> get_index_of_first_last_elemet(vector<int> array , int target) {
    int first_index = get_first_last_index(array , target , true);
    int last_index = get_first_last_index(array , target , false);
    if(first_index !=-1 && last_index !=-1)
        return vector<int> {first_index , last_index};
        else 
            return {-1 , -1};
}
 
int main()
{
	  vector<int> array {5,7,8,8,8,9};
      vector<int> solution = get_index_of_first_last_elemet(array ,8);
      cout<<solution[0]<<":"<<solution[1]<<endl;
}
//if requred to get the number of occurence it is the same position expet of returning vector return first_index - sec_index +1
//which is 4 -2 +1 = 3 time 8 found 
 