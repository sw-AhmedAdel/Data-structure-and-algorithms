#include <iostream>
#include <string>
using namespace std;
//time is o(n)
//space is o 1
/*int get_length_last_word (string word) {
    int count=0;
    int i=0;
    int n = word.length();
    while( i < n) {
        while( word[i] !=' ' && i < n) {
            i++;
            count++;
        }
        while(word[i] ==' ' && i < n) 
            i++;
        if(i==n)
            return count;
            else 
                count=0;
    }
 return count;
 }*/
int get_length_last_word (string word) {
    int count=0;
    int i=0;
    int n = word.length();
    while( i < n) {
        if(word[i] !=' ') {
            count++;
            i++;
        }
            else {
                while(word[i]==' ' && i< n )
                    i++;
                if(i==n)
                    break;
                    else 
                        count=0;
            }
    }
    return count;
}
int main()
{
	 string word= "hello    wolrd   ";
     cout<<get_length_last_word(word)<<endl;
}/*int get(int n) {
    static int count=0;
     if(n > 0) {
         int temp = n%10;
         if(temp ==0)
             count++;
         n= n/10;
         get(n);
     }
     return count;
}
int main()
{ 
    cout<<get(102030);
}*/
