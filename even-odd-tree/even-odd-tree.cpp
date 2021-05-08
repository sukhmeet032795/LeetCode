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
    bool isEvenOddTree(TreeNode* root) {
        
        if(root == NULL)
            return true;
        
        queue<TreeNode*> q;
        q.push(root);
        bool check = true;
        
        while(!q.empty())
        {
            int n = q.size();
            TreeNode *prev = NULL;
            while(n--)
            {
                TreeNode* tmp = q.front();
                q.pop();
                
                if(tmp->left)
                    q.push(tmp->left);
                
                if(tmp->right)
                    q.push(tmp->right);
                
                if(check)
                {
                    if(tmp->val % 2 == 0)
                        return false;

                    if(prev != NULL && tmp->val <= prev->val)
                        return false;
                }
                else
                {
                    if(tmp->val % 2 != 0)
                        return false;

                    if(prev != NULL && tmp->val >= prev->val)
                        return false;
                }
                prev = tmp;
            }
            check = !check;
        }
        
        return true;
    }
};