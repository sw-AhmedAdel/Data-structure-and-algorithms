#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;
void sums(int arr[], int n, int k) {
    for(int i=0 ; i<n-1 ; i++) {
        for(int c=i+1 ; c<n ;c++) {
            if(arr[i]+ arr[c] == k)
                cout<<arr[c]<<":"<<arr[i]<<endl;
        }
    }
}


vector<int> get_sum( int k ,vector<int> numbers) {
    vector<int> num;
    unordered_set<int> sets;
    for(auto v : numbers) 
    {
        int find_num= k-v;
        if(sets.find(find_num)!= sets.end())
        {
            num.push_back(find_num);
            num.push_back(v);
        }else 
            sets.insert(v);
    }
    return num;
} 
 int main(){
    int arr[]= {6,3,8,10,16,7,5,2,9,1};
    int k=10;
    sums(arr,10,k);  
 }
/*int main()
{
	vector<int>arr {6,3,8,10,16,7,5,2,9,1};
     int k=10;
     sort(arr.begin(),arr.end());
     vector<int> v=get_sum(k,arr);
     
     for(auto vv:v)
         cout<<vv<<endl;
 
}*/
/*int main(){
    int arr[]= {6,3,8,10,16,7,5,2,9,1};
    int k=10;
    int hash[16+1];
    for(int i=0 ;i<17 ;i++)
        hash[i]=0;
    
    for(int i=0 ; i<10 ; i++) {
        if(arr[i] <k) {
        if(hash[k-arr[i]] != 0)
            cout<<arr[i]<<":"<<k-arr[i]<<endl;
            else 
                hash[arr[i]]++;
        }
    
    }}*/