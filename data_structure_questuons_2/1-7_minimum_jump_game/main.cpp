#include <iostream>
#include <vector>
using namespace std;
//time is on space 1 
int minimum_jump_game(vector<int> array) {
 if(array.size() == 1)
     return 0;
 if(array.size() ==0)
     return -1;
 int ladder = array[0];
 int stairs = array[0];
 int jump =1;
 for(int i=1 ; i<(int)array.size(); i++) {
     if(i == (int)array.size()-1)
         return jump;// means i got to the last index in array
     if(i + array[i] > ladder)
         ladder = i+array[i]; // means i got to the next larger ladder just save it till i finish the all stair after that 
         //make stair = new ladder - i to jump to the new ladder >> just draw 
        stairs--;
    if(stairs == 0) {
        if(i >= ladder) /* means if i is bigger or equal than the leader means the i is after the last lader and there is no  new ladder to conintue */
            return -1; // why this will give me 0 stairt or <0 so how can i move forward
        stairs= ladder - i;// jump on the new ladder
        jump++;
    }
 }
 return -1;
}


/*int minimum_jump_game(vector<int> array) {
  int jump =0;
  int l=0;
  int r=0;
  while( r < (int)array.size()-1) {
      int fahrest =0;
      for(int i = l ; i <r+1 ; i++)
          fahrest= max(fahrest , i+array[i]);
     l=r+1;
     r= fahrest;
     jump++;
  }
  return jump;
}*/

int main()
{                  
	 //vector<int> arr{2,3,1,1,4};
      vector<int> arr{1,4,3,7,1,2,7,6,7,6,10};
     cout<<minimum_jump_game(arr)<<endl;
}
