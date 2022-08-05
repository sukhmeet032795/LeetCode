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
        
        unordered_map<TreeNode*, TreeNode*> m;
        m[root] = NULL;
        
        queue<TreeNode*> q1;
        q1.push(root);
        
        while(q1.size()) {  
            TreeNode* tmp = q1.front();
            q1.pop();
            
            if (tmp->left) {
                m[tmp->left] = tmp;
                q1.push(tmp->left);
            };
            
            if (tmp->right) {
                m[tmp->right] = tmp;
                q1.push(tmp->right);
            };
        };
        
        unordered_set<TreeNode*> s;
        TreeNode* curr = p;
        while(curr) {
            s.insert(curr);
            curr = m[curr];
        };
        
        curr = q;
        while(curr) {
            if (s.find(curr) != s.end()) {
                return curr;
            };
            curr = m[curr];
        };
        
        return NULL;
    }
};