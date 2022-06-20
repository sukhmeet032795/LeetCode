class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        
        int rows = matrix.size(), cols = matrix[0].size();
        
        int sRow = 0, sCol = 0;
        while(sRow != (rows-1) && sCol !=(cols-1)) {
            int tRow = sRow, tCol = sCol;
            for( ; tCol < cols; tCol++) {
                swap(matrix[tRow][tCol], matrix[tCol][tRow]);
            }
            sRow += 1;
            sCol += 1;
        }
        
        for(int i = 0; i < rows; i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};