#include <iostream>
#include <string>
using namespace  std;


// 1> 2> 3> 4> 5> 6  
//      7 > 8  >9       13 > 14
//           10  > 11
// Definition for a Node.
//solotuon is 1 2  7  8  10 11 9 3 4 5 6 13 14
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};


class Solution {
public:
    Node* flatten(Node* head) {
        
        Node * current = head;
        while(current != nullptr) {
            if(current->child == nullptr) {
                current = current->next;
            }
            else {
                Node * next_node= current->next;
                Node * child_node = current->child;
                current->child= nullptr;
                current->next= child_node;
                child_node->prev= current;
                while (child_node->next != nullptr) {
                    child_node = child_node->next;
                }
                if(next_node != nullptr) 
                {
                next_node->prev = child_node;     
                }
                child_node->next= next_node;
                 current = current->next;
            
          }
        }
        return head;
    }
};