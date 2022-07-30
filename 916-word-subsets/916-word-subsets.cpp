class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        int count2[26] = {0};
        vector<string> ans;
        
        for(int i = 0;i < words2.size();i++) {
            int countAt[26] = {0};
            for(char c  : words2[i]) {
                countAt[c-'a']++;
            }
            
            for(int j = 0;j < 26;j++) {
                if(countAt[j] > count2[j]) count2[j] = countAt[j];
            }
        }
        
        bool flag;
        for(string s : words1) {
            int count1[26] = {0};
            for(char c  : s) {
                count1[c-'a']++;
            }
            
            flag = true;
            
            for(int i = 0;i < 26;i++) {
                if(count1[i] < count2[i]) {
                    flag = false;
                    break;
                }
            }
            
            if(flag) ans.push_back(s);
        }     
        
        return ans;
    }
};