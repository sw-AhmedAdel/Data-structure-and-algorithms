#include <iostream>
#include <string>
#include <vector>
using namespace std;


void get_missing_number(int arr[10], int hash_table[] , vector<int> & numbers , int max) {
    for(int i=0 ; i<10 ;i++) {
        hash_table[arr[i]]++;
    }
    for(int i=1 ;i<max ; i++) {
        if(hash_table[i] ==0)
            numbers.push_back(i);
    }
}

void display(vector <int>  numbers) {
    for(auto n : numbers)
        cout<<n<<" ";
    cout<<endl;
}

int main()
{
	int arr[10] {3,7,4,9,25,6,1,11,2,10};
    int max=25+1;
    int hash_table[max] {0,0,0,0,0,0,0,0,0,0,0,0};
    vector<int> numbers;
    get_missing_number(arr,hash_table,numbers , max);
    display(numbers);


}
