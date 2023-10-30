bool countBits(int const &num1, int const &num2) {
    int count_x = 0, count_y = 0;
    int x = num1, y = num2;

    while(x > 0) {
        count_x += x & 1;

        x >>= 1;
    }
    
    while(y > 0) {
        count_y += y & 1;

        y >>= 1;
    }

    if(count_x == count_y) {
        return num1 < num2;
    }

    return count_x < count_y;
}

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        std::sort(arr.begin(), arr.end(), countBits);

        return arr;
    }
};