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
    vector<int> largest;

    void dfs(TreeNode* node, int depth) {
        if(node == nullptr) return;

        if(largest.size() < depth) {
            largest.push_back(node->val);
        } else {
            largest[depth-1] = max(largest[depth-1], node->val);
        }

        if(node->left != nullptr) {
            dfs(node->left, depth+1);
        }
        if(node->right != nullptr) {
            dfs(node->right, depth+1);
        }
    }

    vector<int> largestValues(TreeNode* root) {
        dfs(root, 1);
        return largest;
    }
};