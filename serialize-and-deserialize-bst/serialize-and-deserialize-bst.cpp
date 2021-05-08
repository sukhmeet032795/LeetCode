/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        if(root == NULL)
            return "";
        
        list<TreeNode*> q;
        q.push_back(root);
        
        string ans = "";
        
        while(!q.empty())
        {   
            int n = q.size();
            while(n--)
            {
                TreeNode* tmp = q.front();
                q.pop_front();

                if(tmp == NULL)
                {
                    ans.append(":,");
                    continue;
                }

                ans.append(to_string(tmp->val) + ",");
                
                q.push_back(tmp->left);
                q.push_back(tmp->right);
            }
        };
        ans.erase(ans.end()-1);
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        TreeNode *head = NULL, *curr = NULL;
        queue<TreeNode*> q;
        
        stringstream ss(data);
        string tmp;
        int op = 1;
        
        while(getline(ss, tmp, ','))
        {
            if(head == NULL)
            {
                head = new TreeNode(stoi(tmp));
                q.push(head);
                continue;
            };
            
            switch(op)
            {
                case 1:
                    {
                        if(tmp == ":")
                            q.front()->left = NULL;
                        else
                        {
                            TreeNode* node = new TreeNode(stoi(tmp));
                            q.front()->left = node;
                            q.push(node);
                        }
                        op = 2;
                    }
                    break;
                case 2:
                    {
                        if(tmp == ":")
                            q.front()->right = NULL;
                        else
                        {
                            TreeNode* node = new TreeNode(stoi(tmp));
                            q.front()->right = node;
                            q.push(node);
                        }
                        op = 3;
                    }
                case 3:
                    {
                        q.pop();
                        op = 1;
                    }
            };
        };
        
        return head;
        // return NULL;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;