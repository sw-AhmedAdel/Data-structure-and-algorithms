#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;
 
 class TrieNode {
public:
  unordered_map<char, TrieNode *> children;
};

class SuffixTrie {
public:
  TrieNode *root;
  char endSymbol;
  SuffixTrie(){
      root= new TrieNode();
  }
};
int main()
{
     TrieNode* r1 = new TrieNode;
     TrieNode* r2 = new TrieNode;
     TrieNode* r3 = new TrieNode;
     r1->children.insert({'r',r2});
     r2->children.insert({'t',r3});
     r3->children.insert({'*', nullptr});
     TrieNode * node = r1;
     vector<char> s{'r','t','*'};
     for(int i= 0 ; i< 3 ; i++) {
         if(node->children.find('*')==node->children.end() )
             node= node->children[s[i]];
             else 
                 cout<<"found"<<endl;
     }

     
  
     
 }
