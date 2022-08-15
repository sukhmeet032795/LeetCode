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
    void insertToLL(ListNode** head, ListNode** tail, ListNode* curr) {
        
        if ((*head) == nullptr) {
            (*head) = (*tail) = curr;    
        } else {
            (*tail)->next = curr;
            (*tail) = (*tail)->next;
        };
    };
    
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode* head = nullptr, *tail = nullptr, *tmp = nullptr;
        
        while(list1 && list2) {
            if (list1->val <= list2->val) {
                insertToLL(&head, &tail, list1);
                list1 = list1->next;
            } else {
                insertToLL(&head, &tail, list2);
                list2 = list2->next;
            }
        };
        
        while(list1) {
            insertToLL(&head, &tail, list1);
            list1 = list1->next;
        };
        
        while(list2) {
            insertToLL(&head, &tail, list2);
            list2 = list2->next;
        };
        
        if (tail)
            tail->next = nullptr;
        return head;
    }
};