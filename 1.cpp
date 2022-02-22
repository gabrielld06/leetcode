#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> nums, int target) {
        map<int, int> memo;
	
		for(int i = 0;i < nums.size();i++) {
			if(memo[target - nums[i]]) {
				return vector<int>({memo[target - nums[i]]-1, i});
			}
			
			memo[nums[i]] = i+1;
		}
		return vector<int>();
    }
};

int main() {
	
	assert(Solution().twoSum(vector<int>({ 2,7,11,15 }), 9) == vector<int>({ 0,1 }));
	assert(Solution().twoSum(vector<int>({ 3,2,4 }), 6) == vector<int>({ 1, 2 }));
	assert(Solution().twoSum(vector<int>({ 3,3 }), 6) == vector<int>({ 0, 1 }));
	
	return 0;
}