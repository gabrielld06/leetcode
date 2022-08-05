class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        while(i < numbers.size()) {
            for(int j = i+1;j < numbers.size() and numbers[i] + numbers[j] <= target;j++) {
                if(numbers[i] + numbers[j] == target) return vector<int>({i+1, j+1});
            }
            
            while(i < numbers.size()-1 and numbers[i+1] == numbers[i]) {
                i++;
            }
            
            i++;
        }
        
        return vector<int>();
    }
};