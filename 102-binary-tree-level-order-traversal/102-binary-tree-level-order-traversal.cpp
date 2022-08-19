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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        if (!root)
            return {};
        
        queue<TreeNode*> q;
        q.push(root);
        
        vector<int> tmp;
        vector<vector<int>> out;
        
        while(!q.empty()) {
            int n = q.size();
            while(n--) {
                TreeNode* tmp1 = q.front();
                tmp.emplace_back(tmp1->val);
                q.pop();

                if (tmp1->left)
                    q.push(tmp1->left);

                if (tmp1->right)
                    q.push(tmp1->right);
            }
            out.emplace_back(tmp);
            tmp.clear();
        };
        return out;
    }
};