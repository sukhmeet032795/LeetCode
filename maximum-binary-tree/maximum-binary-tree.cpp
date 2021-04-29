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
    
    int getMaxInd(vector<int> &nums, int start, int end)
    {
        int ind = INT_MAX, Max = INT_MIN;
        for(int i = start; i <= end; i++)
        {
            if(Max < nums[i])
            {
                Max = nums[i];
                ind = i;
            }
        };  
        return ind;
    };
    
    TreeNode* generateTree(vector<int> &nums, int start, int end)
    {
        if(start > end)
            return NULL;
        
        int ind = getMaxInd(nums, start, end);
        TreeNode* node = new TreeNode(nums[ind]);
        
        node->left = generateTree(nums, start, ind-1);
        node->right = generateTree(nums, ind+1, end);
        
        return node;
    };
    
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        
        int len = nums.size();
        return generateTree(nums, 0, len-1);
    };
};