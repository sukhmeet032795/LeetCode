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
    void makestr(TreeNode* t, string &ans)
    {
        if(t == NULL)
            return;
        
        ans += "(" + to_string(t->val);
        
        if(t->left == NULL && t->right == NULL)
        {
            ans += ")";
            return;
        }
        
        if(t->left == NULL && t->right != NULL)
        {
            ans += "()";
        }
        
        if(t->left)
            makestr(t->left, ans);
        if(t->right)
            makestr(t->right, ans);
        ans += ")";
    }
    
    string tree2str(TreeNode* t) {
        
        if(t == NULL)
            return "";
        
        string ans = "";
        makestr(t, ans);
        
        ans.erase(ans.begin());
        ans.erase(ans.end()-1);
        
        return ans;
    }
};