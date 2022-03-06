/**
https://leetcode.com/problems/symmetric-tree/submissions/
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * time n and space n for rec 
 * };
 */
class Solution {
public:
 
  bool helper(TreeNode* left , TreeNode* right) {
       if(left==nullptr && right ==nullptr) return true;
       if(left!=nullptr && right ==nullptr) return false;  
      if(left==nullptr && right !=nullptr) return false;
         
       if(left->val ==right->val &&  helper(left->left, right->right)
          &&helper(left->right,right->left) )
             return true;
         else return false;
         
     }
    
    bool isSymmetric(TreeNode* root) {
        if(root==nullptr)
            return true;
     return helper(root->left , root->right);
    
    }
   
};