class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size()-1;
        int ans = min(height[l], height[r]) * (r - l);
        // cout << ans << " "<< min(height[l], height[r]) << " " << l << " " << r << " " << (r - l) << endl;
        while(l < r) {
            if(height[l] < height[r]) {
                l = l + 1;
            } else {
                r = r - 1;
            }
            
            ans = max(min(height[l], height[r]) * (r - l), ans);
            // cout << ans << " "<< min(height[l], height[r]) << " " << l << " " << r << " " << (r - l) << endl;
        }
        return ans;
    }
};