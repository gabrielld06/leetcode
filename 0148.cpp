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
	void merge(ListNode*  list[], int l, int mid, int r) {
		int sizeLeftArray = mid-l+1, sizeRightArray = r-mid;
		int leftArray[sizeLeftArray], rightArray[sizeRightArray];
		for(int i = 0;i < sizeLeftArray;i++) {
			leftArray[i] = list[l+i]->val;
		}
		for(int i = 0;i < sizeRightArray;i++) {
			rightArray[i] = list[mid+i+1]->val;
		}
		
		int leftArrayIndex = 0, rightArrayIndex = 0, auxIndex = l;
		while(leftArrayIndex < sizeLeftArray and rightArrayIndex < sizeRightArray) {
			if(leftArray[leftArrayIndex] < rightArray[rightArrayIndex]) {
				list[auxIndex]->val  = leftArray[leftArrayIndex];
				leftArrayIndex++;
			} else {
				list[auxIndex]->val  = rightArray[rightArrayIndex];
				rightArrayIndex++;
			}
			auxIndex++;
		}
		while(leftArrayIndex < sizeLeftArray) {
			list[auxIndex]->val  = leftArray[leftArrayIndex];
			leftArrayIndex++;
			auxIndex++;
		}
		while(rightArrayIndex < sizeRightArray) {
			list[auxIndex]->val = rightArray[rightArrayIndex];
			rightArrayIndex++;
			auxIndex++;
		}
	}
	
	void mergeSort(ListNode* list[], int l, int r) {
		if(l < r) {
			int mid = l + (r - l) / 2;
			mergeSort(list, l, mid);
			mergeSort(list, mid+1, r);
			merge(list, l, mid, r);
		}
	}
	
    ListNode* sortList(ListNode* head) {
        int len = 0;
		ListNode* at = head;
		while(at != nullptr) {
			at = at->next;len++;
		}
		ListNode* list[len];
		at = head;
		for(int i = 0;i < len;i++) {
			list[i] = at;
			at = at->next;
		}
		mergeSort(list, 0, len-1);
		return head;
    }
};

void print(ListNode* at) {
	if(at == nullptr) cout << endl;
	else {
		cout << at-> val << " ";
		print(at->next);
	}
}

int main() {
	
	//Input: head = [4,2,1,3]
	//Output: [1,2,3,4]
	ListNode* l = new ListNode(4, new ListNode(2, new ListNode(1, new ListNode(3))));
	print(l);
	l = Solution().sortList(l);
	print(l);
	//assert(Solution().sortList(l) == new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4)))));
	
	return 0;
}