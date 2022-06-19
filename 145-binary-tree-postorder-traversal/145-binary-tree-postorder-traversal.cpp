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
    vector<int> postorderTraversal(TreeNode* root) {
        
        if (!root) return {};
        
        stack<TreeNode*> s;
        TreeNode* curr = root;
        
        vector<int> out;
        
        while(!s.empty() || curr!= NULL) {
            if (curr) {
                out.push_back(curr->val);
                s.push(curr);
                curr = curr->right;
            }
            else {
                curr = s.top();
                s.pop();
                curr = curr->left;
            }
        }
        
        reverse(out.begin(), out.end());
        return out;
    }
};