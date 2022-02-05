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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        priority_queue<int, vector<int>, greater<int>> p;
        int len = lists.size();
        
        map<int, list<ListNode*>> m;
        for(int i = 0; i < len; i++)
        {
            if(lists[i] != NULL)
            {
                p.push(lists[i]->val);
                m[lists[i]->val].push_back(lists[i]);
            }
        };
        
        ListNode *head = NULL, *curr = NULL;
        
        while(!p.empty())
        {
            int top = p.top();
            p.pop();
            
            ListNode* tmp = m[top].front();
            m[top].pop_front();
            
            if(m[top].size() == 0)
            {
                m.erase(top);
            };
            
            if(tmp->next)
            {
                p.push(tmp->next->val);
                m[tmp->next->val].push_back(tmp->next);
            }
            
            if(head == NULL)
            {
                head = new ListNode(top);
                curr = head;
            }
            else
            {
                ListNode* tmp1 = new ListNode(top);
                curr->next = tmp1;
                curr = tmp1;
            }
        }
        
        return head;
    }
};