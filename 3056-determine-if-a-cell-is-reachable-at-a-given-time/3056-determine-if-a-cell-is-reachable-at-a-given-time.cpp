class Solution {
public:
    bool isReachableAtTime(int x, int y, int fx, int fy, int t) {
        if(x == fx && y == fy && t == 1) return false;
        if(x == fx && y == fy) return true;

        int d = min(abs(x - fx), abs(y - fy));

        if(x < fx) {
            x += d;
        } else {
            x -= d;
        }

        if(y < fy) {
            y += d;
        } else {
            y -= d;
        }

        int l = abs(x - fx) + abs(y - fy);

        return d + l <= t;
    }
};