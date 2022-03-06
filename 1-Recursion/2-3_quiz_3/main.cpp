#include <iostream>
#include <string>
using namespace std;


void count(int n) {
static int d = 1; 
printf("%d", n); 
printf("%d", d); 
d++; 
if (n > 1) 
    count (n-1); 
printf("%d", d);
         } 

int main( ) 
{
  count (3);
} 


/*int fun (int n){ 
  int x=1, k ; 
  if (n==1) return x; 
  for (k=1; k<n; ++k) {
     x=x + fun (k) * fun (n - k); 
  }
return x; 
}
int main(){
    cout<<fun(5)<<endl;
}

        
        /*
int fun(int &x , int c ) {
    c =c-1;
    if(c==0)
        return 1;
    x=x+1;
    return fun(x , c) *x;
}

int main()
{
	int x{5};
    cout<<fun(x , x)<<endl;
}
*/