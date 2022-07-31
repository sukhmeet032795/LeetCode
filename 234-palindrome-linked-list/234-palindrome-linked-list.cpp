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
    bool checkPalin(ListNode* head, ListNode** tail) {
        
        if (head == NULL)
            return true;
        
        bool check = checkPalin(head->next, tail);
        
        if (!check || (head->val != (*tail)->val))
            return false;
        
        (*tail) = (*tail)->next;
        return true;
    };
    
    bool isPalindrome(ListNode* head) {
        
        return checkPalin(head, &head);
    }
};