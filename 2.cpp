#include <bits/stdc++.h>

using namespace std;

struct ListNode {
	int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		if(l1 == nullptr and l2 == nullptr) {
			return nullptr;
		}
		if(l1 == nullptr) {
			if(l2->val >= 10) {
				l2->val %= 10;
				if(l2->next != nullptr)
					l2->next->val += 1;
				else
					return new ListNode(l2->val, new ListNode(1));	
			}
			return new ListNode(l2->val, Solution().addTwoNumbers(l1, l2->next));
		}
		if(l2 == nullptr) {
			if(l1->val >= 10) {
				l1->val %= 10;
				if(l1->next != nullptr)
					l1->next->val += 1;
				else
					return new ListNode(l1->val, new ListNode(1));	
			}
			return new ListNode(l1->val, Solution().addTwoNumbers(l1->next, l2));
		}
		int sum = l1->val + l2->val;
		if(l1->val + l2->val >= 10) {
			sum %= 10;
			if(l1->next != nullptr)
				l1->next->val += 1;
			else if(l2->next != nullptr)
				l2->next->val += 1;
			else
				return new ListNode(sum, new ListNode(1));	
		}
		return new ListNode(sum, Solution().addTwoNumbers(l1->next, l2->next));	
    }
};

int main() {	
	//Input: l1 = [2,4,3], l2 = [5,6,4]
	//Output: [7,0,8]
	ListNode* l1 = new ListNode(2, new ListNode(4, new ListNode(3)));
	ListNode* l2 = new ListNode(5, new ListNode(6, new ListNode(4)));
	
	assert(Solution().addTwoNumbers(l1, l2) == new ListNode(7, new ListNode(0, new ListNode(8))));
	
	return 0;
}