class Solution {
public:
    int lowerBound(vector<int>& nums, int target, int i, int j) {
        if(i >= j) {
            if(i < 0 || i >= nums.size()) {
                return (nums[j] == target ? j : -1);
            }
            if(j < 0 || j >= nums.size()) {
                return (nums[i] == target ? i : -1);
            }

            return (nums[j] == target ? j : (nums[i] == target ? i : -1));
        }

        int mid = (i + j) / 2;

        if(nums[mid] == target) {
            return lowerBound(nums, target, i, mid);
        } else if(nums[mid] < target) {
            return lowerBound(nums, target, mid+1, j);
        } else {
            return lowerBound(nums, target, i, mid);
        }
    }

    int upperBound(vector<int>& nums, int target, int i, int j) {
        if(i >= j) {
            if(i < 0 || i >= nums.size()) {
                return (nums[j] == target ? j : -1);
            }
            if(j < 0 || j >= nums.size()) {
                return (nums[i] == target ? i : -1);
            }

            return (nums[i] == target ? i : (nums[j] == target ? j : -1));
        }

        int mid = (i + j + 1) / 2;

        if(nums[mid] == target) {
            return upperBound(nums, target, mid, j);
        } else if(nums[mid] < target) {
            return upperBound(nums, target,  mid+1, j);
        } else {
            return upperBound(nums, target, i, mid-1);
        }
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0) {
            return vector<int>({-1, -1});
        }

        cout << "lower" << endl;

        int lower = lowerBound(nums, target, 0, nums.size()-1);
        cout << "upper" << endl;
        int upper = upperBound(nums, target, 0, nums.size()-1);

        return vector<int>({lower, upper});
    }
};