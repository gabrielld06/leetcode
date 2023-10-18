/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
	void mergeSort(ListNode* vet[], int b, int e) {
        if (b >= e) {
            return;
        }

        int mid = (b + e) / 2;

        mergeSort(vet, b, mid);
        mergeSort(vet, mid + 1, e);

        ListNode *vet_aux = (ListNode *)malloc((e - b + 1) * sizeof(ListNode));

        // Copy elements in order to aux
        int i = b, j = mid + 1, k = 0;
        while (i <= mid && j <= e) {
            while (i <= mid && vet[i]->val <= vet[j]->val) {
                vet_aux[k].val = vet[i]->val;
                i++;
                k++;
            }

            if (i > mid) break;

            while (j <= e && vet[j]->val <= vet[i]->val) {
                vet_aux[k].val = vet[j]->val;
                j++;
                k++;
            }
        }

        // Copy remainder
        while (i <= mid) {
            vet_aux[k].val = vet[i]->val;
            i++;
            k++;
        }
        while (j <= e) {
            vet_aux[k].val = vet[j]->val;
            j++;
            k++;
        }

        // Copy back to vet
        for (int i = b, k = 0; i <= e; i++, k++) {
            vet[i]->val = vet_aux[k].val;
        }
    }
	
    ListNode* sortList(ListNode* head) {
        int len = 0;
		ListNode* at = head;
		while(at != nullptr) {
			at = at->next;len++;
		}
		ListNode* list[len+1];
		at = head;
		for(int i = 0;i < len;i++) {
			list[i] = at;
			at = at->next;
		}
		mergeSort(list, 0, len-1);
		return head;
    }
};