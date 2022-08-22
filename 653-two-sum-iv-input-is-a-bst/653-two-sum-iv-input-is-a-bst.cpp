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
    bool findTarget(TreeNode* root, int k) {
        
        queue<TreeNode*> q;
        unordered_set<int> us;
        q.push(root);
        
        while(!q.empty()) {
            TreeNode* tmp = q.front();
            q.pop();
            
            if (us.find(k - tmp->val) != us.end())
                return true;
            
            us.insert(tmp->val);
            
            if (tmp->left)
                q.push(tmp->left);
            
            if (tmp->right)
                q.push(tmp->right);
        };
        
        return false;
    }
};