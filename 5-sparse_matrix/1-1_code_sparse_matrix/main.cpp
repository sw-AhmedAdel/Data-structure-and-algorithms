#include <iostream>
using namespace std;

class element {
public:
    int row;
    int colum;
    int x;
};

class sparse {
private:
    int m;
    int n;
    int num;
    element *ele;
public:
    sparse(int m, int n, int num) :m{m},n{n} ,num{num} {
        ele=new element [num];
    }
    ~sparse () {
        delete[] ele;
    }
   void read() {
       cout<<"enter the none-zero number"<<endl;
       for(int i=0 ; i<num ; i++) {
           cout<<"loop number >> "<<i<<endl;
           cin >> ele[i].row;
           cin >>ele[i].colum;
           cin>>ele[i].x;
       }
   }
    
   void display() {
       int k=0;
       for(int i=0 ; i<m ; i++) {
           for(int j=0 ;j <n ; j++) {
               if(ele[k].row == i && ele[k].colum==j)
                   cout<<ele[k++].x<<" ";
                   else 
                       cout<<"0 ";
           }
           cout<<endl;
       }
   } 
    
};

int main()
{ 
    sparse s(5,5,5);
    s.read();
    s.display();
    
}
