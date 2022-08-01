/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head, *slow = head;
        
        while(fast != nullptr and fast->next != nullptr) {
            slow=slow->next;
            fast=fast->next->next;
            if(slow == fast) {
                break;
            }
        }
        
        if(fast == nullptr or fast->next == nullptr) return nullptr;
        
        int l = 1;
        slow = slow->next;
        while(slow != fast) {
            slow = slow->next;
            l++;
        }
        
        fast=head, slow = head;
        while(l--) {
            fast=fast->next;
        }
        
        while(slow != fast) {
            slow = slow->next;
            fast=fast->next;
        }
        
        return fast;
    }
};