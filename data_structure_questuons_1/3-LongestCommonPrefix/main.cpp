#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
//time is o(mn) which m is the legnth of the smallest char and n is the number of string 
// space o(m) worst case will be the length of the smallest string like flo , flower , flown
//here space is m for flo take the all chars of flo

using namespace std;
#include <vector>


// flo , flower , flown
//flo
string get_loest_string( vector<string>& strings ) {
   string min_string;
   string common_prefix;
  
    min_string = strings[0];//take the first string and compare it with the rest string in the vector
    for(int i=0 ; i<min_string.size() ; i++) {
        for(int j=1 ; j<strings.size(); j++) {
            if(i>=strings[j].size() ||  min_string[i] != strings[j][i])//here j is the first word in the vector and i is the char 
            //if i=0 and j=0 here j for the first string in vector and i is the first char 
            //when j ++ = 1 so it means it is the sec string in vector and i still 0 which is the first char 
            //the next condion to see if i >= the rest string in the vector coz if it is >= means this string less than the min_string
            //means has no any other letter so just stop coz there is no letter and i get the longest common prefixt 
                return common_prefix;
        }
        common_prefix.push_back(min_string[i]);
    }
    return common_prefix;
}
/*string get_loest_string( vector<string>& strings ) {
   string min_string;
   string common_prefix;
  /* int i;
   int j;
   int min= INT_MAX;
   for( i=0 ; i<strings.size() ; i++) {
       j = strings[i].size();
       if( j <min) {
           min=j;
           min_string=strings[i];
       }
    }*/
    /*
    //i can use this method to get the min string
    min_string = * min_element(strings.begin() , strings.end());
    for(int i=0 ; i<min_string.size() ; i++) {
        for(int j=0 ; j<strings.size(); j++) {
            if(min_string[i] != strings[j][i])//here j is the first word in the vector and i is the char 
            //if i=0 and j=0 here j for the first string in vector and i is the first char 
            //when j ++ = 1 so it means it is the sec string in vector and i still 0 which is the first char 
                return common_prefix;
        }
        common_prefix.push_back(min_string[i]);
    }
    return common_prefix;
}*/
int main() 
{
	 vector<string> strings ={"flower" , "flo","flown"};
     cout<<get_loest_string(strings)<<endl;
}
