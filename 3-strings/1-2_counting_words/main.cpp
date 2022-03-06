#include <iostream>
#include <string>
#include <cstring>
using namespace std;


int main()
{
	 char arr[] ={"how  are  you today matte haha"};
     int  non_vowls =0;
     int  count_char=0;
     for(int i=0 ; arr[i] !='\0'; i++) {
         if(arr[i]=='a' || arr[i]=='o' || arr[i]=='u'|| arr[i]=='e')
             count_char++;
             else if( (arr[i]>=65 && arr[i]<=90 )|| (arr[i]>=97 && arr[i]<=122) )
                 non_vowls++;
     }
     cout<<"vowls "<<count_char<<":"<<"others "<<non_vowls<<endl;
     cout<<"___________________________________"<<endl;
     /*int words=0;
     for(int i= 0 ;arr[i]!='\0' ; i++) {
         if(arr[i]==' ' && arr[i-1] !=' ')
             words++;
     }
     words++;
     cout<<"number of words "<<words<<endl;*/
     int size= strlen(arr);
    int s= 0 ;
    int counter = 0;
    while ( s < size ) {
        int e = s;
        while (arr[e] !=' ' && e < size)
            e++;
        if(arr[e-1] !=' ')
            counter++;
        s = e+1;
    }
    cout<<counter<<endl;
    
}
