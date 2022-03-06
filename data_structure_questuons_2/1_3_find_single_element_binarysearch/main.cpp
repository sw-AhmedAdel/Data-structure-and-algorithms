#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;
 // time is log n space is 1
int ge_single_element(vector<int> array) {
    int s=0;
    int e= array.size()-1;
    if(e == 0)
        return 0;//if array is emptu
    if(array[s] != array[s+1])
        return array[s]; // if last element is single 
    if(array[e] != array[e-1])
        return array[e];//if first element is single
    while( s <= e) {
        int mid = (s+e) / 2;
        if(array[mid] != array[mid+1] && array[mid] != array[mid-1])
            return array[mid];
        if( ((mid%2)==1 &&  array[mid]== array[mid-1] ) || ((mid%2)==0 && array[mid]==array[mid+1]))
            s =mid+1;
            else 
                e=mid-1;
    }
    return -1;
    //when mode ==0 then mid = mid+1
 
}

 
int main()
{
	 vector<int> arr{1,1,2,2,3,4,4};
     cout<<ge_single_element(arr)<<endl;
}
