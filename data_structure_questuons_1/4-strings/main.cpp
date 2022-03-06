#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main()
{
	 string names ="abcdef";
     //             012345
     string s1= names.substr(0); // from 0 to the end
     string s2 =names.substr(1);//from 1 to the end
     string s3 = names.substr(3,5);
     cout<<s1<<endl;
     cout<<s2<<endl;
     cout<<s3<<endl;
     cout<<"______________"<<endl;
     cout<<names.find("cd")<<endl;
     cout<<endl;
     int num =123;
     string n_num = to_string(num);
     cout<<n_num<<endl;
     cout<<endl;
     int n = stoi(n_num);
     cout<<n<<endl;
     cout<<"________"<<endl;
     cout<<"______"<<endl;
    
     
}
