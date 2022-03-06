#include <iostream>
 #include <vector>
using namespace std;

int get_max(vector <int> arr) {
	int x=arr[0];
	for(int i=0 ; i<arr.size() ; i++) {
		if(arr[i] > x)
			x=arr[i];
	}
	return x;
}
void radixSort_method(vector<int> & arr ,int max );
void count(vector<int> & arr ,int div , int n);

vector<int> radixSort(vector<int> & array) {
int max=get_max(array);
 radixSort_method( array , max);
  return array;
}

void radixSort_method(vector<int> & arr ,int max){
	for(int div=1 ; max/div >0 ;div=div*10)
		count( arr,div, arr.size());
}
void count(vector<int> & arr ,int div , int n) {
	int temp[n];
	int range=10;
	int count[range] {0};
	
	for(int i=0 ; i< n ; i++)
		count[(arr[i] / div) % 10 ]++;
	
	for(int i=1 ;i<range ;i++)
		count[i]= count[i] + count[i-1];
	
	for(int i=n-1 ; i>=0 ;i--)
		temp[-- count[(arr[i] /div) %10]] = arr[i];
	
	for(int i=0;i<n;i++)
		arr[i]=temp[i];
}


    int main()
{
 vector<int> arr{5555,273,50,214,3507,20,2568,174};
 arr=radixSort(arr);
 for(auto s : arr)
     cout<<s<<" ";
cout<<endl;
	 
}
