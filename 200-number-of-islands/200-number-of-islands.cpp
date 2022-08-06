class Solution {
public:
    void dfs_visit(vector<vector<char>>& grid, int i, int j) {
        if(i < 0 or i >= grid.size() or j < 0 or j >= grid[i].size()) return;
        if(grid[i][j] == '0') return;
        
        grid[i][j] = '0';
        
        dfs_visit(grid, i+1, j);
        dfs_visit(grid, i, j+1);
        dfs_visit(grid, i-1, j);
        dfs_visit(grid, i, j-1);
    }

    int numIslands(vector<vector<char>>& grid) {
        int comp = 0;
        for(int i = 0;i < grid.size();i++) {
            for(int j = 0;j < grid[i].size();j++) {
                if(grid[i][j] == '1') {
                    dfs_visit(grid, i, j);
                    comp++;
                }
            }   
        }
    
        
        return comp;
    }
};