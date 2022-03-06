#include <iostream>
#include <string>
using namespace std;
#include <vector>


void get_missing_array(int arr[11] , int n , vector<int> & numbers) {
    int low=arr[0];
    int diff=low+0;
    for(int i=0 ; i< n ; i++) {
        if(arr[i] -i != diff) {
            while(diff < arr[i]-i) {
                numbers.push_back(diff+i);
                ++diff;
            }
        }else
          continue;
    }
}
void display(vector<int> numbers)  {
    for( auto n : numbers)
        cout<<n<<" ";
    cout<<endl;
}

int main(){
    int n=11;
    int arr[n]={6,7,8,9,11,12,15,16,17,18,19};
    vector<int> numbers;
    get_missing_array(arr ,  n , numbers) ;
    display(numbers);
}