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
    ListNode* sortList(ListNode* head) {
        
        map<int, list<ListNode*>> m;
        ListNode* curr = head;
        
        while(curr) {
            m[curr->val].push_back(curr);
            curr = curr->next;
        };
        
        head = curr = NULL;
        for(auto itr : m) {
            for(auto ll : itr.second) {
                if (head == NULL) {
                    head = curr = ll;
                    curr->next = NULL;
                } else {
                    curr->next = ll;
                    curr = curr->next;
                    curr->next = NULL;
                }
            };
        };
        
        return head;
    }
};