class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;

        ans.push_back(1);
        long last = 1;
        for(int i = 1;i <= rowIndex/2;i++) {
            last =  (last * (rowIndex-i+1)) / i; 
            ans.push_back(last);
        }

        for(int i = (rowIndex % 2 ? 0 : 1);i <= rowIndex/2;i++) {
            ans.push_back(ans[rowIndex/2 - i]);
        }

        return ans;
    }
};