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
        
        ListNode* head = NULL, *curr = head;
        
        auto func = [](ListNode** l, ListNode** head, ListNode** curr) -> void {
            if ((*head) == NULL) { (*head) = (*curr) = (*l); }
            else { (*curr)->next = (*l); (*curr) = (*curr)->next; }
            (*l) = (*l)->next;
        };
        
        while(list1 && list2) {
            
            if (list1->val < list2->val) {
                func(&list1, &head, &curr);
            } else {
                func(&list2, &head, &curr);
            }
        };
        
        while(list1) {
            func(&list1, &head, &curr);
        };
        
        while(list2) {
            func(&list2, &head, &curr);
        };
        
        return head;
    }
};