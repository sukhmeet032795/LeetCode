class Solution {
public:
    
    vector<vector<char>> floodFill(vector<vector<char>>& image, int &sr, int &sc, int &rows, int &cols, char &color) {
        
        queue<pair<int, int>> q;
        q.push(make_pair(sr, sc));
        char startColor = image[sr][sc];
        image[sr][sc] = color;
        
        while(!q.empty()){
            
            auto p = q.front();
            q.pop();
            
            if ((p.second - 1) >= 0 && image[p.first][p.second - 1] == startColor) {
                image[p.first][p.second - 1] = color;
                q.push(make_pair(p.first, p.second - 1));    
            };
            
            if ((p.first - 1) >= 0 && image[p.first - 1][p.second] == startColor) {
                image[p.first - 1][p.second] = color;
                q.push(make_pair(p.first - 1, p.second));    
            };
            
            if ((p.second + 1) < cols && image[p.first][p.second + 1] == startColor) {
                image[p.first][p.second + 1] = color;
                q.push(make_pair(p.first, p.second + 1));    
            };
            
            if ((p.first + 1) < rows && image[p.first + 1][p.second] == startColor) {
                image[p.first + 1][p.second] = color;
                q.push(make_pair(p.first + 1, p.second));    
            };
        };
        
        return image;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        
        int rows = grid.size(), cols = grid[0].size(), count = 0;
        char color = '0';
        
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if (grid[i][j] == '1')
                {
                    count++;
                    grid = floodFill(grid, i, j, rows, cols, color);
                }
            }
        }
        return count;
    }
};