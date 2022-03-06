#include <iostream>
#include <string>
#include <cmath>

using namespace std;
 /* this is Polynomial ;
  *         5    4    2    1   0 this calls coecoefficients
  * p(x) = 3x + 2x + 5x + 2x + 7
  * */
class term {
public: 
    int coefficients;
    int pow;
};

class Polynomial {
private:
    int n;
    term * t;
public:
    Polynomial(int s) {
        n=s;
        t=new term[n];
    }
    
    void read() {
        for(int i=0 ; i<n; i++) {
            cout<<"enter the numbers "<<i+1<<endl;
            cin >>t[i].coefficients;
            cin >>t[i].pow;
        }
    }
    int get_x() {
    int x , total =0;
    cout<<"enter the x"<<endl;
    cin >> x;
    for(int i=0 ; i< n ; i++) {
         total+= t[i].coefficients * pow(x , t[i].pow);
       }
       return total;
    }
    void display() {
        for(int i=0 ; i< n ; i++) {
        cout<<t[i].coefficients<<":"<<t[i].pow<<endl;
    }
    
}
    int get_n() {
        return n;
    }
   Polynomial* addition_Polynomial(Polynomial & p) {
       Polynomial * sum =new Polynomial(n + p.n);// المجموع عدد ارقامهم فا هيعمل  مكان على الهيب فى  تمن اماكن 
        int i=0 , k=0 , j=0;
       while (i < n && j < p.n) {
           if(t[i].pow > p.t[j].pow)
               sum->t[k++]=t[i++];
               else if(p.t[j].pow > t[i].pow)
                   sum->t[k++]=p.t[j++];
                   else {
                       sum->t[k].pow=t[i].pow;
                       sum->t[k++].coefficients = t[i++].coefficients + p.t[j++].coefficients;
                   }
       }
       while(i< n) {
        sum->t[k++]=t[i++];
       }
       while(j < p.get_n()) {
           sum->t[k++]=p.t[j++];
       }
       sum->n=k;// عدلت الاى على اساس كام رقم اتسجل فى الاراى 
       return sum;
   }

};

int main(){
    Polynomial p (3); //5,4/ 2,2 /5,0
    p.read();
    p.display();
   cout<<"___________"<<endl;
    Polynomial pp (5);//6,4 / 5,3 / 9,2 / 2,1 / 3,0
    pp.read();
    pp.display();
    cout<<"______"<<endl;
    Polynomial * sum= p.addition_Polynomial(pp);
    sum->display();
}

