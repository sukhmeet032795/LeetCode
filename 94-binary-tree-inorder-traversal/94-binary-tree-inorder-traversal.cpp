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
    vector<int> inorderTraversal(TreeNode* root) {
        
        if (root == NULL)
            return {};
        
        stack<TreeNode*> s;
        TreeNode* curr = root;
        
        vector<int> out;
        
        while(!s.empty() || curr != NULL) {
            if (curr != NULL) {
                s.push(curr);
                curr = curr->left;
            }
            else {
                curr = s.top();
                s.pop();
                out.push_back(curr->val);
                curr = curr->right;
            }
        }
        return out;
    }
};