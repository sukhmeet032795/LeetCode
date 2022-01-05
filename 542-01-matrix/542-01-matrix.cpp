class Solution {
public:
    
    struct coords {
        int x;
        int y;
        coords(int x1, int y1) {
            x = x1;
            y = y1;
        };
    };
    
    vector<vector<int>> direction = {{-1,0},{0,-1},{1,0},{0,1}};
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> out(m, vector<int>(n, 0));
        queue<coords> q;
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(mat[i][j] == 0)
                    q.push(coords(i, j));
                else
                    out[i][j] = INT_MAX;
            }
        }
        
        while(!q.empty()) {
            coords p = q.front();
            q.pop();
            
            for(int x = 0; x < 4; x++) {
                int x1 = p.x + direction[x][0], y1 = p.y + direction[x][1];
                if(x1 < 0 || y1 < 0 || x1 >= m || y1 >= n)
                    continue;
                if(out[x1][y1] > (out[p.x][p.y] + 1)) {
                    out[x1][y1] = out[p.x][p.y] + 1;
                    q.push(coords(x1, y1));
                }
            }
        }
        
        return out;
    };
};