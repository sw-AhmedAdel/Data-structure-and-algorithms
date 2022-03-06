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
class Solution {//time is n coz i visit each node and space is n for rec
public:
    int maxDepth(TreeNode* root) {
        if(root!= nullptr){
            int x;
            int y;
            x=maxDepth(root->left);
            y=maxDepth(root->right);
            if (x > y)
                return x+1;
            else return y+1;
        }
        return 0;
    }
};/*    if(root== nullptr)
            return 0;
        else {
            int left = maxDepth(root->left);
            int right=maxDepth(root->right);
            return max(left , right) + 1;
        }
    }*/