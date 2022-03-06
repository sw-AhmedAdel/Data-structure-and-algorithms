#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> arr) {
    int max_elemet= arr[arr.size()-1];
    int i=arr.size()-2;
    cout<<max_elemet<<endl;
    while(i >=0) {
        if(arr[i] > max_elemet) {
            max_elemet=arr[i];
            cout<<max_elemet<<endl;
        }
        i--;
    }
}


int main()
{
	 vector<int> arr{15,18,5,3,6,2};
     print(arr);
}
