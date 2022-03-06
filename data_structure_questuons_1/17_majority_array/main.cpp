#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
//here see the number appers in the majority in the array and return it if this number > the size /2
// i can solve it using 2 loops but time will be n*2;
// usnig has map time is n and space is n
//or using sort time is nlogn and space o(1)
//or using some approcah is call moor's voting will give me time n and space 1

int get_majority_number(vector<int> numbers) {
 int counter=1;
 int temp=numbers[0]; 
 for(int i=1 ; i<numbers.size() ; i++) {
     if(temp== numbers[i])
         counter++;
         else if(temp != numbers[i] && counter!=0) 
             counter--;
             else {
                 temp=numbers[i];
                 counter=1;
             }
 }
 return temp;
}
/*
int get_majority_number(vector<int> numbers) {
    unordered_map<int , int> maps;
    int size = numbers.size() / 2;
    for(size_t i=0 ; i<numbers.size() ; i++)
    {
        if(maps.find(numbers[i] )== maps.end())
            maps[numbers[i]]=0;
        maps[numbers[i]]++;
    }
    auto it= maps.begin();
    while(it != maps.end()) {
        if(it->second > size)
            return it->first;
      it++;
    }
    
    return -1;
}*/
int main()
{
    vector<int> numbers{2,2,1,1,2,1,2};
    cout<<get_majority_number(numbers)<<endl;
}
