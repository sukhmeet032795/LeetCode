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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        if(!root)
            return {};
        
        stack<TreeNode*> s1, s2;
        s1.push(root);
        
        vector< vector<int> > out;
        vector<int> arr;
        
        while(!s1.empty() || !s2.empty())
        {
            while(!s1.empty())
            {
                TreeNode* tmp = s1.top();
                s1.pop();
                
                arr.push_back(tmp->val);
                
                if(tmp->left)
                    s2.push(tmp->left);
                
                if(tmp->right)
                    s2.push(tmp->right);
            };
            
            if(!arr.empty())
                out.push_back(arr);
            
            arr.clear();
            while(!s2.empty())
            {
                TreeNode* tmp = s2.top();
                s2.pop();
                
                arr.push_back(tmp->val);
                
                if(tmp->right)
                    s1.push(tmp->right);
                
                if(tmp->left)
                    s1.push(tmp->left);
            };
            
            if(!arr.empty())
                out.push_back(arr);
            
            arr.clear();
        }
        
        return out;
    }
};