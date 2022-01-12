/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     Node *left;
 *     Node *right;
 *     Node *random;
 *     Node() : val(0), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x) : val(x), left(nullptr), right(nullptr), random(nullptr) {}
 *     Node(int x, Node *left, Node *right, Node *random) : val(x), left(left), right(right), random(random) {}
 * };
 */

class Solution {
public:
    
    map<Node*, NodeCopy*> m;
    NodeCopy* createTree(Node* root) {
        
        if(root == NULL)
            return NULL;
        
        NodeCopy* tmp = new NodeCopy(root->val);
        m[root] = tmp;
        
        tmp->left = createTree(root->left);
        tmp->right = createTree(root->right);
        
        return tmp;
    };
    
    void createRandomNodes(Node* root, NodeCopy* newRoot) {
        
        if(root == NULL)
            return;
        
        if(root->random != NULL)
        {
            newRoot->random = m[root->random];
        }
        
        createRandomNodes(root->left, newRoot->left);
        createRandomNodes(root->right, newRoot->right);
    };
    
    NodeCopy* copyRandomBinaryTree(Node* root) {
        
        m.clear();
        NodeCopy* newRoot = createTree(root);
        createRandomNodes(root, newRoot);
        return newRoot;
    }
};