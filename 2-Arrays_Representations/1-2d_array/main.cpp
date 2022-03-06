#include <iostream>
#include <string>
using namespace std;

int main()
{
	int x=1;
    int arr[3][3] ;
    for(int i=0 ; i<3 ; i++) {
        for(int c=0 ;c<3 ; c++) {
            arr[i][c] =x;
            x++;
        }
    }
     for(int i=0 ; i<3 ; i++) {
        for(int c=0 ;c<3 ; c++) {
            cout<<arr[i][c]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    ///////////using dynamic array///////////////////
    int *p [3];
    for(int i=0 ; i< 3 ; i++) {
        p[i]=new int[3];
        for(int c=0 ; c<3 ; c++) {
            p[i][c]=x;
            x++;
        }
    }
    for(int i=0 ; i<3 ; i++) {
        for(int c=0 ;c<3 ; c++) {
            cout<<p[i][c]<<" ";
        }
        cout<<endl;
    }
         cout<<endl;
    ///////////////// using double ** in heap for dynamic array
    int **pp;
    pp=new int *[3];
    for(int i=0 ; i<3 ; i++) {
        pp[i]=new int[3];
        for(int c=0 ; c<3 ; c++) {
            p[i][c]=x;
            x++;
        }
    }
    for(int i=0 ; i<3 ; i++) {
        for(int c=0 ;c<3 ; c++) {
            cout<<p[i][c]<<" ";
        }
        cout<<endl;
    }


    delete[]p;
    
    
}
/*  int *p[3];
    int x=1;
    int size;
    int arr[3];
    int counter=0;
    for(int i=0 ; i<3 ; i++) {
        cout<<"enter the size"<<endl;
        cin >> size;
        p[i]=new int[size];
        arr[counter]=size;
        counter++;
        for(int c=0 ; c<size; c++) {
            p[i][c]=x;
            x++;
        }
    }
    for(int i=0 ; i<3 ; i++) {
        for(int c=0 ; c<arr[i] ; c++)
            cout<<p[i][c]<<" ";
        cout<<endl;
    }*/
    
    /*
 
int main(){
  int **p;
  int length;
  cout<<"enter the length of dynamic array"<<endl;
  cin >> length;
  p =new int * [length];
  int c=1;
  int arr[length];
  int counter=0;
  for(int i=0 ; i<length ; i++) {
      cout<<"enter the size"<<endl;
      int size;
      cin >>size;
      p[i]=new int[size];
      arr[counter]=size;
      counter++;
      for(int x=0 ; x<size ; x++) {
          p[i][x]=c;
          c++;
          
      }
      cout<<endl;
  }
  
  
  for(int i=0 ; i<length ; i++) {
      for(int c=0 ; c<arr[i] ;c++)
          cout<<p[i][c]<<" ";
      cout<<endl;
  }
}*/