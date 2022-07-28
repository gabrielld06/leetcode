#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    map<vector<int>, vector<string>> mp;

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        for(auto str : strs) {
            vector<int> abc(26, 0);
            for(auto c : str) {
                abc[c - 'a']++;
            }

            mp[abc].push_back(str);
        }

        vector<vector<string>> ans;
        for(auto [key, value]: mp) {
            ans.push_back(value);
        }

        return ans;
    }
};

// Example 1:

// Input: strs = ["eat","tea","tan","ate","nat","bat"]
// Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
// Example 2:

// Input: strs = [""]
// Output: [[""]]
// Example 3:

// Input: strs = ["a"]
// Output: [["a"]]

int main() {

    vector<string> strs = vector<string>({"eat","tea","tan","ate","nat","bat"});

    vector<vector<string>> ans = Solution().groupAnagrams(strs);

    for(auto vet : ans) {
        for(auto str : vet) {
            cout << str << " ";
        }
        cout << endl;
    }

    return 0;
}