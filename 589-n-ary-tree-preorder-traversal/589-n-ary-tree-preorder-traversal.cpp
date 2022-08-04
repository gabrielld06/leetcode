/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        if(root == nullptr) return vector<int>();
        
        vector<int> ans;
        
        ans.push_back(root->val);
        
        for(auto child : root->children) {
            vector<int> child_vec = preorder(child);
            if(child_vec != vector<int>()) ans.insert(ans.end(), child_vec.begin(), child_vec.end());
        }
        
        
        return ans;
    }
};