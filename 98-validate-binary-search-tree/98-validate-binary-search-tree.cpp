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
    vector<int> order;
    
    void traverse(TreeNode* at) {
        if(at==nullptr) return;
        traverse(at->left);
        order.push_back(at->val);
        traverse(at->right);
    }
    
    bool isValidBST(TreeNode* root) {
        traverse(root);
        
        for(int i = 1; i < order.size();i++) {
            if(order[i] <= order[i-1]) return false;
        }
        
        return true;
    }
};