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
    
    void getInorderTraversal(TreeNode* root, vector<int>& arr) {
        if(root == NULL)
            return;
        getInorderTraversal(root->left, arr);
        arr.push_back(root->val);
        getInorderTraversal(root->right, arr);
    }
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> output, arr1, arr2;
        getInorderTraversal(root1, arr1);
        getInorderTraversal(root2, arr2);
        
        int i = 0, j = 0;
        while(i < arr1.size() && j < arr2.size()) {
            if(arr1[i] < arr2[j]) {
                output.push_back(arr1[i]);
                i++;
            }
            else {
                output.push_back(arr2[j]);
                j++;
            }
        }
        
        while(i < arr1.size())
            output.push_back(arr1[i++]);
        
        while(j < arr2.size())
            output.push_back(arr2[j++]);
        
        return output;
    }
};