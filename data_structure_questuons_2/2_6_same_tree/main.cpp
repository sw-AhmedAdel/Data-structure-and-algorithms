#include <iostream>
#include <string>
using namespace  std;

//https://leetcode.com/problems/same-tree/submissions/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 //time is min(m+n) coz the minim tree rec will stop.. space is the same
class Solution {
public:
    bool isSameTree(TreeNode* a, TreeNode* b) {
        if(a==nullptr && b==nullptr) return true;
        if(a==nullptr && b!= nullptr) return false;
        if(a != nullptr && b==nullptr) return false;
        
        if(a->val == b->val && isSameTree(a->left , b->left) && isSameTree(a->right, b->right))
            return true;
        else 
            return false;
    }
};