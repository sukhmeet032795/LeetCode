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
    ListNode* deleteDuplicates(ListNode* head) {
        
        if(!head || !head->next)
            return head;
        
        ListNode *curr = head, *next = head->next;
        
        while(curr != NULL && next != NULL) {
            
            if (curr->val == next->val) {
                curr->next = next->next;
            } else {
                curr = curr->next;
            };
            next = next->next;
        };
        return head;
    };
};