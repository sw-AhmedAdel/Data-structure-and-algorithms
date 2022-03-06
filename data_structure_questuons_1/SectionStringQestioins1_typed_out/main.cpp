#include <iostream>
#include <string>
#include <vector>
using namespace std;
/*   string string1 {"abc#d"};
     string string2 {"abzzzzz#####d"};*/
     //time is a+b a length of array1 and b length of array2 and spce is 1

void check (int & index , string str) {
          int counter=0;
           while(str[index]=='#'&&index >=0) {
               counter++;
               index--;
           }
           while(counter >0 & index>= 0) {
               index--;
               counter--;
           }
}
bool typed_out(string array1 , string array2 ) {
   int i=array1.size()-1;
   int j=array2.size()-1;
   while (i >=0 || j >=0) {
       //why coz this string string2 {"abzzzzz#####d"} s
      if(array1[i]=='#' || array2[j]=='#' ) {
          if(array1[i]=='#') {

              check(i , array1);
          }
        if(array2[j] =='#') {
     
            check( j , array2 );
           }
       }else {
           if(array1[i] != array2[j])
               return false;
               else {
                   i--;
                   j--;
               }
       }
   }
   
   return true;
}


/*
//time is o(a+b) a the length of the first array and b is the length of sec array space is o(a+b)
string check_string (string array) {
    vector<char> s ;
    for(size_t i=0 ; i<array.size() ; i++) {
        if(array[i] !='#')
            s.push_back(array[i]);
            else if(array[i]=='#')
                s.pop_back();
    }
    return string(s.begin() , s.end());
}

bool typed_out(string array1 , string array2 ) {
  string arr1 =check_string(array1);
  string arr2=check_string(array2);
  if(arr1.size() !=arr2.size())
      return false;
      else {
          for(size_t i=0 ; i<arr1.size() ; i++) {
              if(arr1[i] != arr2[i])
                  return false;
          }
      }
      return true;
}
*/
int main()
{
	 string string1 {"abc#d"};
     string string2 {"abzzzzz#####d"};
     if(typed_out(string1 , string2 ) == true)
         cout<<"true"<<endl;
         else 
             cout<<"false"<<endl;
    
      
    
 
}
