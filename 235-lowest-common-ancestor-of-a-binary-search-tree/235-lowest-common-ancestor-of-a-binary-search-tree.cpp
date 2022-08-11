/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if (root == NULL)
            return root;
        
        unordered_map<TreeNode*, TreeNode*> m;
        m[root] = NULL;
        
        queue<TreeNode*> q1;
        q1.push(root);
        
        while(!q1.empty()) {
            TreeNode* tmp = q1.front();
            q1.pop();
            
            if (tmp->left) {
                m[tmp->left] = tmp;
                q1.push(tmp->left);
            }
            
            if (tmp->right) {
                m[tmp->right] = tmp;
                q1.push(tmp->right);
            }
        };
        
        unordered_set<TreeNode*> s1;
        TreeNode* curr = p;
        while(curr) {
            s1.insert(curr);
            curr = m[curr];
        };
        
        curr = q;
        while(curr) {
            if (s1.find(curr) != s1.end()) {
                return curr;
            };
            curr = m[curr];
        };
        
        return NULL;
    }
};