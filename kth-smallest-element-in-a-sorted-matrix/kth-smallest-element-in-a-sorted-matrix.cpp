class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        priority_queue<int> p;
        int rows = matrix.size(), cols = matrix[0].size();
        
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < cols; j++)
            {
                if(p.size() < k)
                {
                    p.push(matrix[i][j]);
                    continue;
                }
                
                if(j == 0 && p.top() < matrix[i][j])
                    break;
                
                if(!p.empty() && p.top() > matrix[i][j])
                {
                    p.pop();
                    p.push(matrix[i][j]);
                }
            }
        }
        
        return p.top();
    }
};