class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        
        int rows = mat.size(), cols = mat[0].size(), rInd = 0, cInd = 0;
        
        if ((rows*cols) != (r*c))
            return mat;
        
        vector<vector<int>> out(r, vector<int>(c, 0));
        for (int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                out[i][j] = mat[rInd][cInd++];
                
                if (cInd == cols) {
                    rInd += 1;
                    cInd = 0;
                };
            };
        };
        
        return out;
    }
};