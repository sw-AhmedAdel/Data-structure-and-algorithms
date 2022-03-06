#include <iostream>
#include <vector>
using namespace std;
int binary_search_in_rotatedArray(vector<int> array , int target) {
    int s=0;
    int e= array.size()-1;
    while(s <=e) {
        int mid = (s+e) / 2 ;
        if(array[mid] == target)
            return mid;
            
            else if(array[s] < array[mid]) {//why? coz i want to check the targer int this section if this true i will do some operations
            if(target >= array[s] && target <=array[mid]) {
                //means this targer hit the mid but it is not the mid so it is between the s and the mid so go left using e= mid-1
                e= mid-1;
            }else 
                //means in this section is not found so go to the other section
                s= mid+1;
                
            }else {
                // this means the middl in the array is in the seaction smallest number like 4 5 6 1 2 3 4 mid=3 which is 1 so 4 !< 1
                if(target >= array[mid] && target <=array[e])
                    s= mid+1; // why coz the mid = 3 and the sec section is 1 2 3 4 so s <e means 1 <4 yes so go to the right
                    else 
                        e=mid-1;//this condtion for 4 5 6 0 1 2 3
                        //mid is 0 so s <mid which is 4 < 0 no ok the other conditon if 4 > s && < e which is 4 >0 && < 3 no
                        //so go tp the left 
            }
    }
    
    return -1;
}

int main()
{
    // vector<int> array{4,5,6,1,2,3,4};
     //cout<<binary_search_in_rotatedArray(array , 2)<<endl;
     
     vector<int> array{4,5,6,7,0,1,2};
     cout<<binary_search_in_rotatedArray(array , 0)<<endl;
}
