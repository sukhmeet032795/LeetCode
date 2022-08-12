class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int rows = matrix.size(), cols = matrix[0].size();
        int row = 0, col = (cols - 1);
        
        while(row < rows && col < cols && row >= 0 && col >= 0) {
            
            if (matrix[row][col] == target)
                return true;
            
            if (matrix[row][col] > target)
                col--;
            else
                row++;
        };
        return false;
    }
};