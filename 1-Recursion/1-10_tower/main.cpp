#include <iostream>
#include <string>
using namespace std;

/*void tower(int n, int a , int b , int c) {
    if(n > 0) {
        tower(n-1, a,c,b );
        cout<<a<<":"<<c<<endl;
        tower(n-1,b,a,c);
    }
}
int main()
{
    tower (3,1,2,3);
	return 0;
}
/*int get_path(int n , int m) {
    if(n ==1 || m==1)
        return 1;
        else 
            return get_path(n ,m-1) + get_path(n-1, m);
}

int main(){
    cout<<get_path(2,3)<<endl;
}*/

void print(int s , int e) {
    cout<<s<<":"<<e<<endl;
}

void tower(int n, int s, int e) {
    if(n==1)
        print(s,e);
        else {
            int middle= 6 -(s+e);
            tower(n-1,s,middle);
            print(s,e);
            tower(n-1,middle,e);
        }
}

int main()
{
    tower (3,1,3);
	return 0;
}


 