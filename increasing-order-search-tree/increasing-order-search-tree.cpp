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
    
    void print2DUtil(TreeNode *root, int space) 
    { 
        // Base case 
        if (root == NULL) 
            return; 

        // Increase distance between levels 
        space += 10; 

        // Process right child first 
        print2DUtil(root->right, space); 

        // Print current node after space 
        // count 
        cout<<endl; 
        for (int i = 10; i < space; i++) 
            cout<<" "; 
        cout<<root->val<<"\n"; 

        // Process left child 
        print2DUtil(root->left, space); 
    } 

    // Wrapper over print2DUtil() 
    void print2D(TreeNode *root) 
    { 
        // Pass initial space count as 0 
        print2DUtil(root, 0); 
    } 
    
    TreeNode* increasingBST(TreeNode* root) {
        
        TreeNode *newRoot = NULL, *curr = NULL, *curr1 = root;
        
        queue<TreeNode*> q;
        stack<TreeNode*> s;
        while(curr1 != NULL || !s.empty())
        {
            if(curr1)
            {
                s.push(curr1);
                curr1 = curr1->left;
            }
            else
            {
                curr1 = s.top();
                s.pop();
                q.push(curr1);
                curr1 = curr1->right;
            }
        }
        
        while(!q.empty())
        {
            if(newRoot == NULL)
            {
                newRoot = curr = q.front();
            }
            else
            {
                curr->right = q.front();
                curr = curr->right;
            }
            curr->left = NULL;
            q.pop();
        }
        
        return newRoot;
    }
};