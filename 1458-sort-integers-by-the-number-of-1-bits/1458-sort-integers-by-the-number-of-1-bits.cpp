int memo[10001];

class Solution {
public:
    static bool countBits(int x, int y) {
        int count_x = 0, count_y = 0;
        int num1 = x, num2 = y;

        while(x > 0) {
            if(memo[x] != -1) {
                count_x += memo[x];
                break;
            }

            count_x += x & 1;

            x = x >> 1;
        }

        memo[x] = count_x;
        
        while(y > 0) {
            if(memo[y] != -1) {
                count_y += memo[y];
                break;
            }

            count_y += y & 1;

           y = y >> 1;
        }

        memo[y] = count_y;

        if(count_x == count_y) {
            return num1 < num2;
        }

        return count_x < count_y;
    }

    vector<int> sortByBits(vector<int>& arr) {
        memset(memo, -1, sizeof(memo));

        std::sort(arr.begin(), arr.end(), countBits);

        return arr;
    }
};