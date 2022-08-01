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
class Solution {
public:
    int traverse(TreeNode* at) {
        if(at == nullptr) return 1;
        
        int left = traverse(at->left), right = traverse(at->right);
        
        if(left == -1 or right == -1) return -1;
        
        if(abs(left - right) <= 1 ) {
            return max(left, right) + 1;
        } else {
            return -1;
        }
    }
    
    bool isBalanced(TreeNode* root) {
        
        
        if(traverse(root) == -1) return false;
        return true;
    }
};