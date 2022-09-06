class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size()-1;
        int ans = min(height[l], height[r]) * (r - l), a;
        while(l < r) {
            if(height[l] < height[r]) {
                l = l + 1;
            } else {
                r = r - 1;
            }
            a = (height[l] < height[r] ? height[l] : height[r]) * (r - l);
            ans = (a > ans ? a : ans);
        }
        return ans;
    }
};