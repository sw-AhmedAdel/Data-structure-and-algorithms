#include <iostream>
#include <string>
using namespace std;

bool check_palandrom(string array , int s, int e) {
    while( s<e) {
        if(array[s] != array[e])
            return false;
            else {
                s++;
                e--;
            }
    }
    return true;
}
bool is_palindrom(string array) {
    int s=0;
    int e=array.size()-1;
    while( s < e) {
        if(array[s] != array[e]) {
            if(check_palandrom(array , s+1 , e) || check_palandrom(array,s,e-1))
                //here see if i deleted or pass i char will have paladeom like abca here if i delete c i will have palandrom
                
                return true;
                else 
                    return false;
        }
        else {
            s++;
            e--;
        }
    }
    return true;
}

int main()
{
	 string array{"abccdba"};
     
     cout<<is_palindrom(array)<<endl;
}
