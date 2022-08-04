class Solution {
public:    
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> p;
        
        for(int i = 0; i < mat.size();i++) {
            int sum = 0;
            for(auto e : mat[i]) {
                sum += e;
            }
            
            p.push_back(pair<int,int>(sum, i));
        }
        
        sort(p.begin(), p.end());
        
        vector<int> ans;
        for(int i = 0;i < k;i++) {
            ans.push_back(p[i].second);
        }
        
        return ans;
    }
};