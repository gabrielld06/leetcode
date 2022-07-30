class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle == "") return 0;
        int j, index;
        for(int i = 0;i < haystack.length();i++) {
            index = i, j = 0;
            while(index < haystack.length() and j < needle.length() and haystack[index] == needle[j]) {
                j++;
                index++;
            }
            if(j == needle.length()) return i;
        }
        
        return -1;
    }
};