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
    bool isCompleteTree(TreeNode* root) {
        
        if(root == NULL)
            return true;
        
        bool check = false;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            TreeNode* tmp = q.front();
            q.pop();
            
            if(tmp->left)
            {
                if(check == true)
                    return false;
                q.push(tmp->left);
            }
            else
            {
                check = true;
            }
            
            if(tmp->right)
            {
                if(check == true)
                    return false;
                q.push(tmp->right);
            }
            else
            {
                check = true;
            }
        }
        
        return true;
    }
};