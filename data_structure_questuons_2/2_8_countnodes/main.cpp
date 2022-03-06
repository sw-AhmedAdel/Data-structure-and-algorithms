/**https://leetcode.com/problems/count-complete-tree-nodes/submissions/
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
class Solution {
public:
    int countNodes(TreeNode* root) {
        int x;
        int y;
        if(root != nullptr) {
            x=countNodes(root->right);
            y=countNodes(root->left);
            return x + y + 1;
        }else 
            return 0;
    }
    /*
     *      if(root ==nullptr)
           return 0;
       
        return countNodes(root->left) + countNodes(root->right) + 1;
    }*/
};