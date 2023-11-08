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
    map<int, int> mp;
    int max_ap = 0;

    void count(TreeNode* node) {
        if(node == nullptr) return;

        mp[node->val]++;

        if(mp[node->val] > max_ap) max_ap = mp[node->val];

        count(node->left);
        count(node->right);
    }

    vector<int> findMode(TreeNode* root) {
        count(root);

        vector<int> ans;
        for(auto e : mp) {
            if(e.second == max_ap) ans.push_back(e.first);
        }

        return ans;
    }
};