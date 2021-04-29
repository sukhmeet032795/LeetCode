/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        
        stack<TreeNode*> s1, s2;
        TreeNode* curr1 = original, *curr2 = cloned;
        
        while(!s1.empty() || curr1 != NULL)
        {
            if(curr1)
            {
                s1.push(curr1);
                s2.push(curr2);
                curr1 = curr1->left;
                curr2 = curr2->left;
            }
            else
            {
                curr1 = s1.top();
                curr2 = s2.top();
                s1.pop();
                s2.pop();
                
                if(curr1 == target)
                    return curr2;
                
                curr1 = curr1->right;
                curr2 = curr2->right;
            }
        }
        
        return NULL;
    }
};