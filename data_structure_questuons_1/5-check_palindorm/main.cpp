#include <iostream>
#include <string>
using namespace std;


bool is_palindrom (string array) {
        int s=0;
        int n = array.size();
        int e = n-1;
        
        while(s<e){
            
            while(s<e && !isalnum(array[s]))
               s++;
            while(s<e && !isalnum(array[e]))
               e--;
            
            if(toupper(array[s]) != toupper(array[e])) 
                 return false;
            else {
            s++;
            e--;
        }
        
        }  
     return true;
    }

int main()
{
	 string array ={"Aaa aa b  aaaa a "};
     cout<<is_palindrom(array)<<endl;
}
