/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* at = root;
        
        while((p->val < at->val and q->val < at->val) or (p->val > at->val and q->val > at->val)) {
            while(p->val < at->val and q->val < at->val) {
                at = at->left;
            }
            while(p->val > at->val and q->val > at->val) {
                at = at->right;
            }
        }
        
        return at;
    }
};