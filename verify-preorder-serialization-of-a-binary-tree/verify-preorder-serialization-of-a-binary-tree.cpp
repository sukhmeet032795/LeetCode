class Solution {
public:
    
//     struct treeNode{
//         int data;
//         treeNode* left;
//         treeNode* right;
//         treeNode(int d) : data(d), left(NULL), right(NULL) {};
//     };
    
//     treeNode* generateTree(int &currInd, int &length, vector<string> &data, bool &check)
//     {
//         if(currInd >= length)
//             return NULL;
        
//         if(data[currInd] == "#"){
//             currInd += 1;
//             return NULL;
//         };
        
//         treeNode* val = new treeNode(stoi(data[currInd]));
//         currInd += 1;
        
//         if(currInd >= length)
//         {
//             check = false;
//             return val;
//         }
        
//         val->left = generateTree(currInd, length, data, check);
        
//         if(currInd >= length)
//         {
//             check = false;
//             return val;
//         }
        
//         val->right = generateTree(currInd, length, data, check);
        
//         return val;
//     };
    
    vector<string> getData(string preorder)
    {
        vector<string> out;
        stringstream ss(preorder);
        string tmp;
        
        while(getline(ss, tmp, ','))
        {
            out.push_back(tmp);
        };
        
        return out;
    };
    
    bool isValidSerialization(string preorder) {
        
        vector<string> strs = getData(preorder);
        int cnt = 0;
        for (int i = 0; i < strs.size(); ++i) {
            if (strs[i] == "#") {
                if (cnt == 0) {
                    return i == (strs.size() - 1);
                }
                --cnt;
            } else {
                ++cnt;
            }
        }
        return false;
    }
    
//     bool isValidSerialization(string preorder) {
        
//         bool check = true;
//         vector<string> data = getData(preorder);
//         int currInd = 0, length = data.size();
        
//         generateTree(currInd, length, data, check);
        
//         if(currInd < length)
//             return false;
        
//         return check;
//     }
};