class Solution {
public:
    int comecome(vector<int>& piles, int ans) {
        int r = 0;
        for(auto e : piles) {
            r += ((e - 1) / ans) + 1;
        }
        
        return r;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        long max_e = *max_element(piles.begin(), piles.end());

        
        if(piles.size() == h) return max_e;
        
        long mid, r, b = 1, e = max_e;
        int ans = max_e;
        while(b < e) {
            mid = b + (e - b) / 2;
            
            r = comecome(piles, mid);
            
            if(r == h and mid < ans) {
                ans = mid;
                e = mid;
            }
            else if(r == h and mid >= ans) return ans;
            else if(r < h) e = mid;
            else if(r > h) b = mid + 1;
        }
        return e;
    }
};