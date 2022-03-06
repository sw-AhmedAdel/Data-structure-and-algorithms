#include <iostream>
#include <string>
#include <vector>
using namespace std;
 
//https://leetcode.com/problems/linked-list-cycle-ii/submissions/ 
    /* to put the string in 3 rows
     * pa
     * apl  
     * yi
     * */
    string convert(string str, int nrows) {
      int row=0;
      int step ;
      int n = str.size();
      string * s = new string[nrows];
      for(int i=0 ; i< n ; i++) {
          s[row].push_back(str[i]);
          if(row==0)
              step=1;
          if(row == nrows-1)
              step =-1;
         row = row+ step;
      }
      str="";
      for(int i=0 ; i<nrows ;i++)
          str = str+ s[i];
     return str;
    }
 int main()
{
 
}
