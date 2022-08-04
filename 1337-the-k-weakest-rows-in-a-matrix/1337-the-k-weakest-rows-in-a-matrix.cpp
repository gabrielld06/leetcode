bool compare(pair<int, int> x, pair<int, int> y) {
    if(x.first == y.first) {
        return x.second < y.second;
    }
    return x.first < y.first;
}

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
        
        sort(p.begin(), p.end(), compare);
        
        vector<int> ans;
        for(int i = 0;i < k;i++) {
            ans.push_back(p[i].second);
        }
        
        return ans;
    }
};