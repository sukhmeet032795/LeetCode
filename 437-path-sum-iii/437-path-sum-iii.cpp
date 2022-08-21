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
    int res = 0;
    int pathSum(TreeNode* root, int x) {
        unordered_map<long long,int>mp;
        mp[0]= 1;
        solve(root,x,mp,0);
        return res;
    }
    
    void solve(TreeNode *root, int x,unordered_map<long long,int>mp, long long  cur)
    {
        if(root == NULL)
            return;
        cur += root->val;
        res += mp[cur - x];
        mp[cur]++;
        solve(root->left,x,mp,cur);
        solve(root->right,x,mp,cur);
    }
};