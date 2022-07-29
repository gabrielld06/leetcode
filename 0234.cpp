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
    bool isPalindrome(ListNode* head) {
        ListNode* fast = head, *slow = head;
        
        while(fast != nullptr and fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        ListNode* prev = nullptr, *aux;
        while(slow != nullptr) {
            aux = slow->next;
            slow->next = prev;
            prev = slow;
            slow = aux;
        }
        
        ListNode* left = head, *right = prev;
        while(left and right) {
            if(left->val != right->val) {
                return false;
            }
            left = left->next;
            right = right->next;
        }
        return true;
    }
};