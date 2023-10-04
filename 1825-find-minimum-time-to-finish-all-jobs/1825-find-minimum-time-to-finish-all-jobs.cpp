class Solution {
public:
    vector<int> dp;
    int best = numeric_limits<int>::max();
    
    static bool desc (int i,int j) { return (i > j); }

    void solve(int at, int n, vector<int>& jobs, int k) {
        if(at == n) {
            best = min(*(max_element(dp.begin(), dp.end())), best);
        }

        if(*max_element(dp.begin(),dp.end()) >= best) return;

        dp[0] += jobs[at];
        solve(at+1, n, jobs, k);
        dp[0] -= jobs[at];

        for(int i = 1;i < k;i++) {
            if(dp[i] >= dp[i-1]) continue;
            dp[i] += jobs[at];
            solve(at+1, n, jobs, k);
            dp[i] -= jobs[at];
        }
    }

    int minimumTimeRequired(vector<int>& jobs, int k) {
        dp = vector<int>(k);

        sort(jobs.begin(), jobs.end(), desc);

        solve(0, jobs.size(), jobs, k);

        return best;
    }
};