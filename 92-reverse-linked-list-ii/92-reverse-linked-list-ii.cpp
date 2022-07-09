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
    ListNode* reverse(ListNode* head, int numSwaps) {
        ListNode *prev = NULL, *curr = head, *next = NULL;
        int n = 0;
        while(curr != NULL && n <= numSwaps) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            n++;
        };
        head->next = curr;
        return prev;
    };
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        if (left == right) return head;
        ListNode* fake = new ListNode(0);
        fake->next = head;
        ListNode* curr = fake;
        for(int i = 1; i < left; i++) curr = curr->next;
        curr->next = reverse(curr->next, (right - left));
        return fake->next;
    }
};