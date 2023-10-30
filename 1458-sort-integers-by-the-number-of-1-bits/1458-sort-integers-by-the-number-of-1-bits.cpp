class Solution {
public:
    static bool countBits(int x, int y) {
        int count_x = 0, count_y = 0;
        int num1 = x, num2 = y;

        while(x > 0) {
            count_x += x & 1;

            x = x >> 1;
        }
        
        while(y > 0) {
            count_y += y & 1;

           y = y >> 1;
        }

        if(count_x == count_y) {
            return num1 < num2;
        }

        return count_x < count_y;
    }

    vector<int> sortByBits(vector<int>& arr) {
        std::sort(arr.begin(), arr.end(), countBits);

        return arr;
    }
};