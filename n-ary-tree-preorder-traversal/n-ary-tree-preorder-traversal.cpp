/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        
        if(root == NULL)
            return {};
        
        stack<Node*> s;
        s.push(root);
        vector<int> out;
        
        while(!s.empty())
        {
            Node *tmp = s.top();
            s.pop();
            
            out.push_back(tmp->val);
            
            auto children = tmp->children;
            for(int i = children.size() - 1; i >= 0; i--)
            {
                s.push(children[i]);
            }
        }
        
        return out;
    }
};