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
    
    friend istream&operator>>(istream & is, sparse & s) ;
    friend ostream&operator<<(ostream&os , sparse & s) ;
};   


   istream&operator>>(istream & is, sparse & s)  {
       cout<<"enter the none-zero number"<<endl;
       for(int i=0 ; i<s.num ; i++) {
           cout<<"loop number >> "<<i<<endl;
           cin >> s.ele[i].row;
           cin >>s.ele[i].colum;
           cin>>s.ele[i].x;
       }
       return is;
   }
    
   ostream&operator<<(ostream&os , sparse & s)  {
       int k=0;
       for(int i=0 ; i<s.m ; i++) {
           for(int j=0 ;j <s.n ; j++) {
               if(s.ele[k].row == i && s.ele[k].colum==j)
                   cout<<s.ele[k++].x<<" ";
                   else 
                       cout<<"0 ";
           }
           cout<<endl;
       }
       return os;
   } 
    

int main()
{ 
    sparse s(5,5,3);
    cin >> s;
    cout<<s;
    
}
