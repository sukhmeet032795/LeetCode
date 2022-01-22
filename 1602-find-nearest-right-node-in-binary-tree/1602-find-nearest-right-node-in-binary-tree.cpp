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
    TreeNode* findNearestRightNode(TreeNode* root, TreeNode* u) {
        
        if (root == NULL || u == NULL)
            return NULL;
        
        queue<TreeNode*> q;
        q.push(root);
        
        bool check = false;
        while(!q.empty()) {
            
            int n = q.size();
            while(n--) {
                TreeNode* tmp = q.front();
                q.pop();
                
                if(check == true)
                    return tmp;
                
                if(tmp->left)
                    q.push(tmp->left);
                
                if(tmp->right)
                    q.push(tmp->right);
                
                if(tmp->val == u->val)
                    check = true;
            }
            
            if(check == true)
                return NULL;
        }
        
        return NULL;
    }
};