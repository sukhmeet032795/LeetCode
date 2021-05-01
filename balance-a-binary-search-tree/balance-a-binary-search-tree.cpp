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
    
    TreeNode* getTree(int start, int end, vector<int> &arr)
    {
        if(start > end)
            return NULL;
        
        int mid = start + (end - start)/2;
        int val = arr[mid];
        
        TreeNode* tmp = new TreeNode(val);
        tmp->left = getTree(start, mid-1, arr);
        tmp->right = getTree(mid+1, end, arr);
        
        return tmp;
    }
    
    TreeNode* balanceBST(TreeNode* root) {
        
        if(root == NULL)
            return root;
        
        vector<int> arr;
        stack<TreeNode*> s;
        
        TreeNode* curr = root;
        
        while(!s.empty() || curr != NULL)
        {
            if(curr)
            {
                s.push(curr);
                curr = curr->left;
            }
            else
            {
                curr = s.top();
                s.pop();
                
                arr.push_back(curr->val);
                curr = curr->right;
            }
        }
        
        int len = arr.size();
        TreeNode* head1 = getTree(0, len-1, arr);
        
        return head1;
    }
};