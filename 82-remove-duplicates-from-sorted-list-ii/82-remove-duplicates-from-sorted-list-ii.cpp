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
        
        if(head == NULL || head->next == NULL)
            return head;
        
        ListNode* fake = new ListNode(0);
        fake->next = head;
        
        ListNode *prev = fake, *curr = fake->next, *next = fake->next->next;
        bool check = false;
        
        while(prev && curr && next) {
            
            if (curr->val == next->val) {
                check = true;
                next = next->next;
                continue;
            }
            
            if (check == true) {
                prev->next = next;
                curr = next;
                next = next->next;
                check = false;
            } else {
                prev = curr;
                curr = next;
                next = next->next;
            }
        }
        
        if(check == true)
            prev->next = NULL;
        
        return fake->next;
    }
};