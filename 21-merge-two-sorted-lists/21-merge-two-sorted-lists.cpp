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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* at1 = list1, *at2 = list2, *ansHead, *ansAt;
        
        if(at1 != nullptr and at2 != nullptr) {
            if(at1->val < at2->val) {
                ansHead = new ListNode(at1->val); 
                at1 = at1->next;
            } else {
                ansHead = new ListNode(at2->val); 
                at2 = at2->next;
            }
        } else if(at1 != nullptr) {
            return at1;
        } else {
            return at2;
        }
        
        ansAt = ansHead;
        
        while(at1 != nullptr and at2 != nullptr) {
            if(at1->val < at2->val) {
                ansAt->next = new ListNode(at1->val); 
                at1 = at1->next;
            } else {
                ansAt->next = new ListNode(at2->val); 
                at2 = at2->next;
            }
            ansAt = ansAt->next;
        }
        
        while(at1 != nullptr) {
            ansAt->next = new ListNode(at1->val); 
            at1 = at1->next;
            ansAt = ansAt->next;
        }
        
        while(at2 != nullptr) {
            ansAt->next = new ListNode(at2->val); 
            at2 = at2->next;
            ansAt = ansAt->next;
        }
        
        ansAt = nullptr;
        
        return ansHead;
    }
};