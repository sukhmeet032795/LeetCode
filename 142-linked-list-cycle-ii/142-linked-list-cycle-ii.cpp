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

        bool check = false;
        ListNode *slow = head, *fast = head;
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            
            if(slow == fast)
            {
                check = true;
                break;
            };
        };
        
        if (!check)
            return NULL;
        
        fast = head;

        while(fast && slow) {
            
            if (slow == fast)
                return slow;
            
            fast = fast->next;
            slow = slow->next;
        };
        
        return NULL;
    }
};