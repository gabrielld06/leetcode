class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int ans = 0, atualN = 0, atualP = 0;
        bool neg = false;
        
        for(int i = 0;i < nums.size();i++) {
            if(nums[i] < 0) {
                neg = not neg;
                if(not neg) {
                    atualP += atualN + 1;
                    atualN = 0;
                } else {
                    atualN += atualP + 1;
                    atualP = 0;
                }
            } else if(nums[i] > 0) {
                atualP++;
            } else {
                atualN = 0, atualP = 0, neg = false;
            }
            
            ans = max(atualP, ans);
        }
        
        atualN = 0, atualP = 0;
        neg = false;
        for(int i = nums.size()-1;i >= 0;i--) {
            if(nums[i] < 0) {
                neg = not neg;
                if(not neg) {
                    atualP += atualN + 1;
                    atualN = 0;
                } else {
                    atualN += atualP + 1;
                    atualP = 0;
                }
            } else if(nums[i] > 0) {
                atualP++;
            } else {
                atualN = 0, atualP = 0, neg = false;
            }
            
            ans = max(atualP, ans);
        }
        
        return ans;
    }
};