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
    vector<double> averageOfLevels(TreeNode* root) {
        
        if(root == NULL)
            return {};
        
        queue<TreeNode*> q;
        q.push(root);
        
        vector<double> ans;
        
        while(!q.empty())
        {
            int n = q.size();
            double sum = 0;
            for(int i = 0; i < n; i++)
            {
                TreeNode *tmp = q.front();
                q.pop();
                
                sum += tmp->val;
                
                if(tmp->left)
                    q.push(tmp->left);
                
                if(tmp->right)
                    q.push(tmp->right);
            };
            ans.push_back(sum/n);
        };
        return ans;
    }
};