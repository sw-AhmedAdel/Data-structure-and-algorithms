#include <iostream>
#include <string>
#include <vector>
using namespace  std;

/* str is i d 
 * i means next element is greater 
 * d means next element  is smallest
 * 
 * so  to solve when it is d means put the largest num so the next will be smallest
 * when it is i put the smallest number so the next will be largest */

vector<int>find_premutation (string str , int n ) {
    vector<int> temp ;
    int s=1;
    int e=n;
    int i=0;
    while(i < str.size()) {
        if(str[i] == 'd') {
            //put the largest so next element is small
            temp.push_back(e);
            e--;
        }else {
            //put the smallest to make next element is larger
            temp.push_back(s);
            s++;
        }
        i++;
    }
    if(s==e)
        temp.push_back(s);
    return temp;
}
 
int main()
{
    string str = "didd";
    int n=5;
    auto vec = find_premutation (str , n);
    for(auto  v : vec) {
        cout<<v<<" ";
    }
    cout<<endl;
    
    
}
