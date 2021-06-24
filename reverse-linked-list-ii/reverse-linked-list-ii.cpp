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
    
    ListNode* reverse(ListNode* h1, int values)
    {
        int ind = 0;
        ListNode* prev = NULL;
        ListNode* curr = h1;
        ListNode* next = NULL;
        
        while(ind <= values && curr != NULL)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            ind++;
        };
        
        if(h1)
            h1->next = curr;
        return prev;
    }
    
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        
        if(head == NULL || left == right)
            return head;
        
        ListNode* fake = new ListNode(0);
        fake->next = head;
        
        ListNode* curr = fake;
        
        for(int i = 0; i < (left - 1); i++)
            curr = curr->next;
        
        curr->next = reverse(curr->next, (right - left));
        
        return fake->next;
    }
};