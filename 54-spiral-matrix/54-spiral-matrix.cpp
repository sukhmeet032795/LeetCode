class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        
        int rows = matrix.size(), cols = matrix[0].size();
        int sRow = 0, sCol = 0, eRow = (rows - 1), eCol = (cols - 1);
        vector<int> out;
        
        while(sRow <= eRow && sCol <= eCol) {
            
            for(int ind = sCol; ind <= eCol; ind++) {
                out.emplace_back(matrix[sRow][ind]);
            };
            sRow++;
            
            for(int ind = sRow; ind <= eRow; ind++) {
                out.emplace_back(matrix[ind][eCol]);
            };
            eCol--;
            
            if (sRow <= eRow) {
                for(int ind = eCol; ind >= sCol; ind--) {
                    out.emplace_back(matrix[eRow][ind]);
                };
                eRow--;
            };
            
            if (sCol <= eCol) {
                for(int ind = eRow; ind >= sRow; ind--) {
                    out.emplace_back(matrix[ind][sCol]);
                };
                sCol++;
            };
        };
        
        return out;
    };
};