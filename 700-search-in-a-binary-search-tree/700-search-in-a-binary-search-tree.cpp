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
    TreeNode* searchBST(TreeNode* root, int val) {
        
        if (!root)
            return nullptr;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            
            int n = q.size();
            while(n--) {
                TreeNode* tmp = q.front();
                q.pop();
                
                if (tmp->val == val)
                    return tmp;
                
                if (tmp->left) q.push(tmp->left);
                if (tmp->right) q.push(tmp->right);
            };
        };
        return nullptr;
    }
};