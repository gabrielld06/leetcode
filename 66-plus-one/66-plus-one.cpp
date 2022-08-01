class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int cin = 1;
        for(int i = digits.size()-1;i >= 0;i--) {
            digits[i] += cin;
            cin = digits[i] / 10;
            if(digits[i] >= 10) {
                digits[i] = digits[i] % 10;
            } else break;
        }
        
        if(cin != 0) digits.insert(digits.begin(), cin);
        
        return digits;
    }
};