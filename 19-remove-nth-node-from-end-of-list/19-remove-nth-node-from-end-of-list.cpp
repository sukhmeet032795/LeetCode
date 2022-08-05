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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* fake = new ListNode(0), *curr = fake;
        fake->next = head;
        
        int len = -1;
        while (curr) { len++; curr = curr->next; }
        
        curr = fake;
        n = len - n;
        while(n--) { curr = curr->next; }
        
        curr->next = curr->next->next;
        return fake->next;
    }
};