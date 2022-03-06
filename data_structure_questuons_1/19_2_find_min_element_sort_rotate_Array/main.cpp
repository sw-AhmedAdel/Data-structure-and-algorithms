#include <iostream>
#include <vector>
using namespace std;


int get_min_element_using_binary_tree(vector<int> array) {
    int s=0;
    int e=array.size()-1;
    int n = array.size();
    while( s <=e) {
        int mid = (s+e) / 2;
        int next = mid+1 %n ;//why coz 4 5 3 2 1 here the min element is 1 so next is out of range so mid+1 % 5 = 0 which is 4
        int prev = ( mid-1 +n ) %n; //why coz 1 2 3 4 5 here mid is index 0 which is 1 so mid 0-1 is -1 this is wrong so +n 
        //-1 +5 = 4 this gives me the last index in array which is 5 so 1 <2 and 1 <5
        if(array[mid] < array[next] && array[mid] < array[prev])
            return array[mid];
            //if the question is about how many rotate is done in this array>> see the main array was 1 2 6 7 8 we shifted it so
            //number of rotate is 3 coz in depends on the largest number which is 6 7 8 take the next index is 3 so return it
           // return mid;
            else if(array[mid] <= array[e])
                e= mid-1;
                //7,8,1,2,3,4,5 here mid is 2 <=5 yes but the i is in the left so go left
                else 
                    s=mid+1;
                    //6 7 8 1 2 here mid is 8 so 8 <= 2 not so go to right
    }
   return -1;
}

int main()
{
	 //vector<int> array {7,8,1,2,3,4,5};
      vector<int> array {6,7,8,9,10,2};
     cout<<get_min_element_using_binary_tree(array)<<endl;
}
