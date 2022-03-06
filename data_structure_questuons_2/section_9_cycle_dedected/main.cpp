#include <iostream>
#include <unordered_set>
#include <unordered_map>>
using namespace  std;

//https://leetcode.com/problems/linked-list-cycle-ii/submissions/ 
//link on leet code for the questions
 // 1  > 2 > 3 >  4  here 4 is pointing to 2 so start the cycle is 2 
        //      |  <    < |
 
   struct ListNode {
       int val;
       ListNode *next;
       ListNode(int x) : val(x), next(NULL) {}
 };
 //better solutions 
 class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        /*we can use map  solution 1
        
        unordered_map<ListNode * , bool> map;
        while(head != nullptr) {
            if(map.find(head) == map.end())
                map[head]= true;
                else 
                    return head;
            head=head->next;
        }*/
        /*--------------------*/
        
        /*     solution 2
            if(head == nullptr)
              return nullptr;
              
            
          ListNode * move1 = head;
          ListNode * move2 = head;

        do {
            move1 = move1->next;
            move2 = move2 ->next;
            if(move2 != nullptr){
                 move2 = move2 ->next;
            }
        }while (move1 != move2 && move1 != nullptr && move2 != nullptr);
        if(move1 == nullptr || move2 == nullptr)
            return nullptr;
        //here the move1 and move2 are pointing to the same node;
        //make one of them == head and keep them moving till the equal each other
        //means i found the node the coz the cycle
        
         move1 = head;
        while (move1 != move2) {
            move1=move1->next;
            move2=move2->next;
        }
        return move1;
    }*/
         //  solution 3
          ListNode * move1 = head;
          ListNode * move2 = head;
      while(move2 != nullptr && move2->next->next != nullptr) {
            move2= move2->next->next;
            move1=move1->next;
            if(move1 == move2)
                break;
      }
      //here they are eqal each other in the cycle so i want to know how many node inside the cycle
      if(move1 == nullptr || move2 == nullptr)
          return NULL;
      move1 = move1->next;
      int counter = 1;
      while( move1 != move2) {
          move1= move1->next;
          counter ++;
      }
      //it is 5 nodes in the cylce so i will use that by creation new node points to the head and move 5 time and stop
       ListNode * one , * two = head;
       while ( counter > 0)  {
           two = two->next;
       counter--;
       }//here i will move one till it is eqal two after that return dedected cycle 
       while(one != two) {
           one= one->next;
       }
       return one;
};
 /*
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
     unordered_set<ListNode *> nodes;
     ListNode * current = head;
        while(current != nullptr) {
            
            if(nodes.find(current) == nodes.end()) {
                nodes.insert(current) ;
                current= current->next;
                
            }
            else 
                return current;
        }
        return nullptr;
    }
};
*/
int main()
{
    
    
      
    
	return 0;
}
