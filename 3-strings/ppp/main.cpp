#include <iostream>
#include <string>
using namespace std;
// hello      world
int get_length(string s) {
    int count=0;
    int i=0;
    int n= s.length();
    while(i < n) {
        if(s[i] !=' ') {
            count++;
            i++;
        }
        else {
            while(i <n && s[i] ==' ')
                i++;
         if(i == n)
            break;
            else 
                count=0;
        }
 
    }
    return count;
}
int main()
{
  string name="hello world";
  cout<<get_length(name)<<endl;
}
