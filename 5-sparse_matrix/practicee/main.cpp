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
   
   sparse* add_sparse (sparse & s) {
   sparse * sum =new sparse(m ,n ,num + s.num);
   int i=0 , j =0 , k =0;
   while(i <num && j < s.num) {
       if(ele[i].row < s.ele[j].row)
           sum->ele[k++]=ele[i++];
           else if(ele[i].row > s.ele[j].row)
               sum->ele[k++]=s.ele[j++];
               else {
                   
               }
   }
   }
    
};

int main()
{ 
    sparse s1(3,3,3);
    s1.read();
    s1.display();
    cout<<"_________"<<endl;
    sparse s2(3,3,4);
    s2.read();
    s2.display();
    cout<<"_________"<<endl;
    sparse * ss;
    ss=s1.add_sparse(s2);
    if(ss == nullptr)
        cout<<"null"<<endl;
        else
           ss->display();
    
}
