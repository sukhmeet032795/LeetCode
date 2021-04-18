/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isUnivalTree(TreeNode* root) {
        
        TreeNode *curr1 = root, *prev = NULL;
        
        stack<TreeNode*> s;
        while(curr1 != NULL || !s.empty())
        {
            if(curr1)
            {
                s.push(curr1);
                curr1 = curr1->left;
            }
            else
            {
                curr1 = s.top();
                s.pop();
                
                if(prev == NULL)
                {
                    prev = curr1;
                }
                else if(prev->val != curr1->val)
                    return false;
                
                curr1 = curr1->right;
            }
        }
        
        return true;
    }
};