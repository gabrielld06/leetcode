class Solution {
public:
    vector<bool> visited;
    vector<int> father;

    bool dfs(int n, vector<int>& leftChild, vector<int>& rightChild) {
        if(n >= leftChild.size() || n < 0) return true;

        if(visited[n]) return false;
        visited[n] = true;

        int left = leftChild[n];
        int right = rightChild[n];

        return  dfs(left, leftChild, rightChild) && dfs(right, leftChild, rightChild);
    }

    void find_root(int n, vector<int>& leftChild, vector<int>& rightChild) {
        if(n >= leftChild.size() || n < 0) return;

        if(visited[n]) return;
        visited[n] = true;

        int left = leftChild[n];
        int right = rightChild[n];

        if(left != -1) {
            father[left]++;
            find_root(left, leftChild, rightChild);
        }
        if(right != -1) {
            father[right]++;
            find_root(right, leftChild, rightChild);
        }
    }

    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        visited = vector<bool>(n, false);
        father = vector<int>(n, 0);

        // find root
        for(int i = 0;i < n;i++) {
            find_root(i, leftChild, rightChild);
        }

        // get root
        int root = -1;
        for(int i = 0;i < n;i++) {
            if(father[i] == 0) {
                if(root == -1) root = i;
                else return false;
            } else if(father[i] > 1) return false;
        }

        if(root == -1) return false;

        visited = vector<bool>(n, false);

        bool r = dfs(root, leftChild, rightChild);
        
        if(!r) return false;

        for(int i = 0;i < n;i++) {
            if(!visited[i]) return false;
        }

        return true;
    }
};