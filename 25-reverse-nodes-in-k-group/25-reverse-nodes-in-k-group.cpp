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
    ListNode* reverse(ListNode* head, int k) {
        ListNode* prev= NULL, *curr = head, *next = NULL;
        int swaps = 0;
        while(curr != NULL && swaps < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            swaps++;
        };
        head->next = curr;
        return prev;
    };
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if (head == NULL)
            return head;
        
        auto getLength = [](ListNode* head) -> int {
            int len = 0;
            ListNode* curr = head;
            while(curr) {
                curr = curr->next;
                len++;
            };
            return len;
        };
        
        int len = getLength(head);
        
        if(len == 1 || k == 1)
            return head;
        
        ListNode* fake = new ListNode(0);
        fake->next = head;
        ListNode* curr = fake;
        
        while(len) {
            if (len < k)
                break;
            curr->next = reverse(curr->next, k);
            for(int j = 0; j < k; j++)
                curr = curr->next;
            len -= k;
        };
        
        return fake->next;
    };
};