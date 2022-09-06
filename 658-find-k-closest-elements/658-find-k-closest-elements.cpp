class Solution {
public:
    int bin_search(vector<int>& arr, int b, int e, int x) {
        if(b >= e) return e;
        
        int mid = b + (e - b) / 2;
        
        if(arr[mid] == x) return mid;
        else if(x < arr[mid]) return bin_search(arr, b, mid, x);
        else return bin_search(arr, mid+1, e, x);
    }
    
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        if(k == arr.size()) return arr;
        if(x < arr[0]) return vector<int>(arr.begin(), arr.begin()+k);
        if(x > arr[arr.size()-1]) return vector<int>(arr.end()-k, arr.end());
        
        vector<int> left_arr;
        vector<int> right_arr;
        
        int index = bin_search(arr, 0, arr.size()-1, x);
        
        if(index > 0 and abs(arr[index] - x) >= abs(arr[index-1] - x)) index = index-1;
        
        int l = index-1, r = index+1, i;
        
        for(i = 1;i < k and l >= 0 and r < arr.size();i++) {
            if(x - arr[l] <= arr[r] - x) {
                left_arr.push_back(arr[l]);
                l--;
            } else {
                right_arr.push_back(arr[r]);
                r++;
            }
        }
        
        while(i < k and l >= 0) {
            left_arr.push_back(arr[l]);
            l--;
            i++;
        }
        while(i < k and r < arr.size()) {
            right_arr.push_back(arr[r]);
            r++;
            i++;
        }
        
        vector<int> ans;
        
        for(int i = left_arr.size()-1;i >= 0;i--) ans.push_back(left_arr[i]);
        ans.push_back(arr[index]);
        for(int i = 0;i < right_arr.size();i++) ans.push_back(right_arr[i]);
        
        return ans;
    }
};