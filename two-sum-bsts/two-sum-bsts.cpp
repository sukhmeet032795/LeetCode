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
    bool twoSumBSTs(TreeNode* root1, TreeNode* root2, int target) {
        
        unordered_set<int> s;
        queue<TreeNode*> q;
        
        q.push(root1);
        while(!q.empty())
        {
            TreeNode* tmp = q.front();
            q.pop();
            
            s.insert(tmp->val);
            
            if(tmp->left)
                q.push(tmp->left);
            
            if(tmp->right)
                q.push(tmp->right);
        };
        
        q.push(root2);
        while(!q.empty())
        {
            TreeNode* tmp = q.front();
            q.pop();
            
            if(s.find(target - tmp->val) != s.end())
                return true;
            
            if(tmp->left)
                q.push(tmp->left);
            
            if(tmp->right)
                q.push(tmp->right);
        }
        
        return false;
    }
};