class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<map<char, int>> count1;
        map<char, int> count2;
        vector<string> ans;
        
        for(int i = 0;i < words1.size();i++){
            count1.push_back(map<char, int>());
            for(char c  : words1[i]) {
                count1[i][c]++;
            }
        }
        
        for(int i = 0;i < words2.size();i++){
            map<char, int> at;
            for(char c  : words2[i]) {
                at[c]++;
                if(at[c] > count2[c]) count2[c] = at[c];
            }
        }
        
        bool flag;
        for(int i = 0;i < words1.size();i++) {
            flag = true;
            for(auto [key, val] : count2) {
                if(count1[i][key] < val) {
                    flag = false;
                    break;
                }
            }
            if(flag) ans.push_back(words1[i]);
        }
      
        
        return ans;
    }
};