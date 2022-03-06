#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace  std;



vector<int> largestRange(vector<int> array) {
	if(array.size()==0)
		return {-1, -1};
  vector<int> numbers ;
  sort(array.begin() , array.end());
	int longest= 1;
	int counter=1;
	int i=0;
	int j=1;

	while( j < array.size())  {
        if(array[j] -1 == array[j-1]) {
            counter++;
        }
        else {
        if(longest <= counter) {
            longest=counter;
            numbers={array[i], array[j-1]};
            counter=1;
            i=j;
            }
        }    
        j++;
    }
        if(longest < counter) {
            return {array[i], array[j-1]};
        }
        else if(longest == counter){
            return {-1 , -1};
        }
        else 
            return numbers;
    
} 

int main()
{
   
     vector<int>array ={1,5,6,2,3,4,10,19,20,};
    auto arr=largestRange(array);
    cout<<arr[0]<<":"<<arr[1]<<endl;

 
}
