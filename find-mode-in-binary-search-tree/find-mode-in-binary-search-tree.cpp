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
    vector<int> findMode(TreeNode* root) {
        
        if(root == NULL)
            return {};
        
        map<int, int> m;
        queue<TreeNode*> q;
        q.push(root);
        
        int Max = INT_MIN;
        
        while(!q.empty())
        {
            TreeNode* tmp = q.front();
            q.pop();
            
            m[tmp->val]++;
            Max = max(Max, m[tmp->val]);
            
            if(tmp->left)
                q.push(tmp->left);
            
            if(tmp->right)
                q.push(tmp->right);
        }
        
        vector<int> out;
        for(auto itr : m)
        {
            if(itr.second == Max)
                out.push_back(itr.first);
        }
        
        return out;
    }
};