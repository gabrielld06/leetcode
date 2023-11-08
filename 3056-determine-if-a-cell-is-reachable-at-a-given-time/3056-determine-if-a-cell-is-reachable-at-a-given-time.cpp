class Solution {
public:
    bool travel(int x, int y, int fx, int fy, int t) {
        if(x == fx && y == fy) {
            return true;
        }

        if(t == 0) {
            return false;
        }

        if(fx > x) {
            x++;
        } else if(fx < x) {
            x--;
        }
    
        if(fy > y) {
            y++;
        } else if(fy < y) {
            y--;
        }

        return travel(x, y, fx, fy, t-1);
    }
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