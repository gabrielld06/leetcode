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
    vector<vector<int>> ans;
    
    void traverse(TreeNode* at, int i) {
        if(ans.size() == i) ans.push_back(vector<int>());
        ans[i].push_back(at->val);
        if(at->left != nullptr) {
            traverse(at->left, i+1);
        }
        if(at->right != nullptr) {
            traverse(at->right, i+1);
        }
    }
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr) return ans;
        traverse(root, 0);
        return ans;
    }
};