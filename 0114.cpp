#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// The "linked list" should use the same TreeNode class where the right child pointer points to the next node in the list and the left child pointer is always null.
// The "linked list" should be in the same order as a pre-order traversal of the binary tree.

// Input: root = [1,2,5,3,4,null,6]
// Output: [1,null,2,null,3,null,4,null,5,null,6]
// Example 2:

// Input: root = []
// Output: []
// Example 3:

// Input: root = [0]
// Output: [0]

class Solution {
public:
    TreeNode *next, *rt;
    
    void flat(TreeNode *at) {
        if(at == nullptr) return;
        next -> right = new TreeNode(at -> val);
        next = next -> right;
        flat(at->left);
        flat(at->right);
    }

    void flatten(TreeNode *root) {
        if(root == nullptr) return;
        
        next = new TreeNode();
        rt = new TreeNode();

        next -> val = root -> val;
        rt = next;

        flat(root->left);
        flat(root->right);

        root->right = rt->right;
        root->left = rt->left;
    }
};

// Input: root = [1,2,5,3,4,null,6]
// Output: [1,null,2,null,3,null,4,null,5,null,6]
// Example 2:

// Input: root = []
// Output: []
// Example 3:

// Input: root = [0]
// Output: [0]

int main () {

    TreeNode* a = new TreeNode(1, new TreeNode(2, new TreeNode(3), new TreeNode(4)), new TreeNode(5, nullptr, new TreeNode(6)));

    Solution().red(a);
    cout << endl;

    Solution().flatten(a);
    Solution().red(a);
    cout << endl;

    TreeNode* b = new TreeNode();

    Solution().red(b);
    cout << endl;

    Solution().flatten(b);
    Solution().red(b);
    cout << endl;

    TreeNode* c = new TreeNode(0);

    Solution().red(c);
    cout << endl;

    Solution().flatten(c);
    Solution().red(c);
    cout << endl;

    return 0;
}