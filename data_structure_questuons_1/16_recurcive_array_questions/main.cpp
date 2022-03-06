#include <iostream>
#include <vector>
using namespace std;
/*
//print all index of element that exits in the array
void print(int arr[] , int n , int element , int i) {
     if(i == n)
         return ;
         else {
             if(arr[i] == element)
                 cout<<i<<endl;
             print(arr, n , element , i+1);
         }
}

int main()
{
	 int arr[] ={5,1,2,6,5,7,5,12,5,9,5};
     print(arr,11,5 , 0);
}
*/
//////////////////////////////////////
//count element in the array  
/*
int count_number_of_elemet(int arr[] , int n , int element) {
 static int count=0; 
 if(n ==0 )
     return count;
     else {
         if(arr[n-1] == element)
             count++;
       return  count_number_of_elemet(arr, n-1 ,element );
     }
}


int count_number_of_elemet(int arr[] , int n , int element) {
 if(n ==0 )
     return 0;
     else {
         if(arr[n-1] == element)
            return 1+ count_number_of_elemet(arr, n-1 ,element );
            else 
                 return count_number_of_elemet(arr, n-1 ,element );
     }
}
int main()
{
	 int arr[] ={5,1,2,6,5,7,5,12,5,9,5,5};
     cout<<count_number_of_elemet(arr,12,5)<<endl;
}*/
/////////////////////////////////////
//save all index of element that exits in the array

/*void count_number_of_elemet(int arr[] , int n , int ele , int i , vector<int> & vec) {
    if(i == n)
        return;
        else {
            if(arr[i] == ele)
                vec.push_back(i);
            count_number_of_elemet(arr , n , ele , i+1 , vec);
        }
}


int count_number_of_elemet(int arr[] , int n , int ele , int i , vector<int> & vec) {
    if(i == n)
        return 0;
        else {
            if(arr[i] == ele) {
                vec.push_back(i);
               return 1+ count_number_of_elemet(arr , n , ele , i+1 , vec);
            }
            else 
                return  count_number_of_elemet(arr , n , ele , i+1 , vec);
        }
}
  
int main()
{
     vector<int> store;
	 int arr[] ={5,1,2,6,5,7,5,12,5,9,5,5};
   cout<< count_number_of_elemet(arr,12,5, 0 , store )<<endl;
     for(auto s : store)
         cout<<s<<" ";
     cout<<endl;
}*/

//////////////////////////
//check palandrom using recuriont

bool is_palindrom(int arr [] , int s , int e) {
    if(s >= e)
        return true;
        else {
            if(arr[s] != arr[e])
                return false;
                else 
                  return  is_palindrom(arr, s+1 , e-1);
        }
}

int main() {
    int arr[] ={1,2,3,4,5,4,3,2,1};
    cout<<is_palindrom( arr, 0 , 8)<<endl;
}