#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& v1, vector<int>& v2) {
        int i = 0, j = 0;
		
		vector<int> v(v1.size() + v2.size());
		
		while(i < v1.size() and j < v2.size()) {
			if(v1[i] <= v2[j]) {
				v[i+j] = v1[i];
				i++;
			}
			else {
				v[i+j] = v2[j];
				j++;
			}
		}
		while(i < v1.size()) {
			v[i+j] = v1[i];
			i++;
		}
		while(j < v2.size()) {
			v[i+j] = v2[j];
			j++;
		}
		if(v.size()%2 == 0) {
			return (v[v.size()/2] + v[v.size()/2-1])/2.0;
		}
		return v[v.size()/2];
    }
};

int main() {
	vector<int> a = {1, 3};
	vector<int> b = {2};
	vector<int> c = {1, 3};
	vector<int> d = {2, 4};
	
	assert(Solution().findMedianSortedArrays(a, b) == 2);
	assert(Solution().findMedianSortedArrays(c, d) == 2.5);
	
	return 0;
}

