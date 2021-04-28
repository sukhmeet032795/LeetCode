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
    
    bool isCousins(TreeNode* root, int x, int y) {
        
        int level1 = INT_MAX, level2 = INT_MAX, level = 1;
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty())
        {
            int n = q.size();
            for(int i = 0; i < n; i++)
            {
                TreeNode* tmp = q.front();
                q.pop();
                
                if(tmp->left && tmp->right && (tmp->left->val == x && tmp->right->val == y || tmp->left->val == y && tmp->right->val == x))
                    return false;
                
                if((tmp->left && tmp->left->val == x) || (tmp->right && tmp->right->val == x)){
                    level1 = level;
                }
                
                if((tmp->left && tmp->left->val == y) || (tmp->right && tmp->right->val == y)){
                    level2 = level;
                }
                
                if(tmp->left){
                    q.push(tmp->left);
                }
                
                if(tmp->right){
                    q.push(tmp->right);
                }
            }
            level++;
        }
        
        if(level1 != level2 || level1 == INT_MAX || level2 == INT_MAX)
            return false;
        return true;
    }
};