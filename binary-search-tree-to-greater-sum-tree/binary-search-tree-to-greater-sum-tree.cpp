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
    TreeNode* bstToGst(TreeNode* root) {
        
        if(root == NULL)
            return NULL;
        
        stack<TreeNode*> s;
        int currVal = 0;
        
        bool start = true;
        TreeNode* curr = root;
        
        while(curr != NULL || !s.empty())
        {
            if(curr)
            {
                s.push(curr);
                curr = curr->right;
            }
            else
            {
                curr = s.top();
                s.pop();
                if(start == true)
                {
                    currVal = curr->val;
                    start = false;
                }
                else
                {
                    int tmp = curr->val;
                    curr->val += currVal;
                    currVal += tmp;
                }
                
                curr = curr->left;
            }
        }
        
        return root;
    }
};