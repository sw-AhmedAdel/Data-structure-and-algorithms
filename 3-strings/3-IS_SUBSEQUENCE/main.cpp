#include <iostream>
#include <iostream>
using namespace std;
//abc // ahbgdc
bool is_sub(string s , string t) {
 int index=0;
 for(int i=0 ; t[i]!='\0' ; i++) {
     if(t[i] == s[index])
         index++;
 }
 if(index >= s.length())
     return true;
     else 
         return false;
}
/* int index=0;
 int i=0;
 int size1=s.length();
 int size2=t.length();
 while(index < size1 && i < size2 ) {
     if(s[index]==t[i])
         index++;
    i++;
 }
  if(index == size1)
      return true;
      else 
          return false;*/
/*bool is_sub(string s , string t) {
  vector<int> hash1(26,0);
  for(int i=0 ; t[i]!='\0' ;i++ ) {
      hash1[t[i]-97]++;
  }
  for(int i=0 ; s[i]!='\0' ;i++ ) {
      hash1[s[i]-97]--;
      if(hash1[s[i]-97]< 0) {
          return false;
      }
  }
  return true;
}*/
int main()
{
	string s {"abc"};
    string t {"ahbgdc"};
    if(is_sub(s,t))
        cout<<"true"<<endl;
        else 
            cout<<"false"<<endl;
}
