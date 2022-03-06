#include <iostream>
#include <string>
#include <cstring>

using namespace std;


int main()
{
	 string name={"ahmed adel"};
     string name_2;
     for(int i=name.length()-1 ; i>=0 ; i--) {
         name_2+=name[i];
     }
     cout<<name_2<<endl;
     cout<<"______________"<<endl;
     char words[]={"google"};
     char words_2[strlen(words)];
     int i;
     i=strlen(words);
     i=i-1;
     int j;
     for( j=0 ; i>=0 ; i-- , j++) {
         words_2[j]=words[i];
     }
     words_2[j]='\0';
     cout<<words<<endl;
     cout<<words_2<<endl;
     cout<<"_____________________"<<endl;
      int x , y;
      for(y=0 ; words[y] !='\0' ; y++) {};
      y=y-1;
      for(x=0 ; x < y ; x++, y--) {
          char temp=words[x];
          words[x]=words[y];
          words[y]=temp;
      }
     cout<<words<<endl;
     /* while(  x < y  ) {
          char temp=words[x];
          words[x]=words[y];
          words[y]=temp;
          x++, y--;
      }*/
}
