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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        
        vector<int> arr;
        vector<vector<int>> ans;
        
        if(root == NULL)
            return ans;
        
        queue<pair<TreeNode*, pair<int, vector<int>>>> q;
        arr.push_back(root->val);
        q.push(make_pair(root, make_pair((sum - root->val), arr)));
        
        while(!q.empty())
        {
            pair<TreeNode*, pair<int, vector<int>>> p = q.front();
            q.pop();
            
            TreeNode* curr = p.first;
            int sum = p.second.first;
            vector<int> temp = p.second.second;
            
            if(sum == 0 && (curr->left == NULL && curr->right == NULL)){
                ans.push_back(temp);
                continue;
            }
            
            if(curr->left){
                temp.push_back(curr->left->val);
                q.push(make_pair(curr->left, make_pair((sum - curr->left->val), temp)));
                temp.pop_back();
            }
            
            if(curr->right){
                temp.push_back(curr->right->val);
                q.push(make_pair(curr->right, make_pair((sum - curr->right->val), temp)));
                temp.pop_back();
            }
        }
        
        return ans;
    }
};