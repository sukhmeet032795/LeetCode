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
    vector<int> rightSideView(TreeNode* root) {
        
        if (!root)
            return {};
        
        vector<int> output;
        queue<TreeNode*> q;
        
        q.push(root);
        
        while(!q.empty()) {
            int n = q.size();
            while(n--) {
                TreeNode* tmp = q.front();
                q.pop();
                
                if (tmp->left)
                    q.push(tmp->left);
                
                if (tmp->right)
                    q.push(tmp->right);
                
                if (n == 0) output.push_back(tmp->val);
            }
        }
        return output;
    }
};