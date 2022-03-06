#include <iostream>
#include <string>
using namespace std;

void display(char arr[]  , int n) {
     int counter=1;
      for(int i=0 ; i< n-1 ; i++) {
         if(arr[i] != -1) {
        for(int c=i+1 ; c<n ; c++) {
            if(arr[i] ==arr[c]) {
                arr[c]=-1;
                counter++;
            }
        }
        if(counter > 1) {
            cout<<"char is "<<arr[i]<<":"<<counter<<endl;
        }
    }
    counter=1;
  }  
}


int main()
{
    int n{8};
    char word[n]="findings";
  //  display(word,n);
    cout<<"____________use hash table__________"<<endl;
    //make has table for 25 index
    //the all char has numbers code so we will sub them from 97 coz it is lower case
    int hash[26] {0};
    for(int i=0; word[i]!='\0' ; i++) {
        hash[word[i] -97] ++;
    }
    for(int i= 0; i<26 ; i++) {
        if(hash[i] > 1){
            int c=i+97;
            cout<<"char is "<<(char)c<<": counter "<<hash[i]<<endl;
        }
    }
 
}
