class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        int rows = triangle.size();
        
        for(int i = 1; i < rows; i++)
        {
            for(int j = 0; j < triangle[i].size(); j++)
            {
                if(j == 0)
                    triangle[i][j] += triangle[i-1][j];
                else if(j == (triangle[i].size() - 1))
                    triangle[i][j] += triangle[i-1][triangle[i-1].size() - 1];
                else
                    triangle[i][j] += min(triangle[i-1][j-1], triangle[i-1][j]);
            }
        }
        
        int Min = INT_MAX;
        for(int i = 0; i < triangle[rows - 1].size(); i++)
            Min = min(Min, triangle[rows-1][i]);
        
        return Min;
    }
};

//     -1
//   2     3
// 1   -1   -3
        
//   1     2
// 1   -1    -3