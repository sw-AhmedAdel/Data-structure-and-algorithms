#include <iostream>
#include <string>
using namespace std;

/*int fub(int n) {
 
    int t_0=0;
    int t_1=1;
    int s;
    for(int i=2 ; i<=n ; i++) {
        s= t_0 + t_1;
        t_0=t_1;
        t_1=s;
    }
    return s;
}*/

/*int fub(int n)  {
    if(n <=1)
        return n;
        else 
            return fub(n-2)+ fub(n-1);
}*/
int f[10]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};

int fub(int n)  {
  if(n ==2)
       return n;
  else if(n==1)
      return 0;
  }else {
      if(f[n-2] ==-1)
          f[n-2]=fub(n-2);
    if(f[n-1] ==-1)
        f[n-1]=fub(n-1);
   
   return f[n-2] + f[n-1];
  }
    
}

int main()
{
	std::cout<<fub(6)<<std::endl;
	return 0;
}
