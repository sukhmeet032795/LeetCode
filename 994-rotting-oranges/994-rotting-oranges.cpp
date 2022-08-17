class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        bool ones = false;
        int rows = grid.size(), cols = grid[0].size();
        queue<pair<int, int>> q;
        
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if (grid[i][j] == 2)
                    q.push(make_pair(i, j));
                if (grid[i][j] == 1)
                    ones = true;
            }
        }
        
        if (!ones)
            return 0;
        
        int days = -1;
        while(!q.empty()) {
            
            int n = q.size();
            days++;
            while(n--) {
                
                auto p = q.front();
                q.pop();
                
                if ((p.first - 1) >= 0 && grid[p.first - 1][p.second] == 1) {
                    grid[p.first - 1][p.second] = 2;
                    q.push(make_pair(p.first - 1, p.second));
                };
                
                if ((p.second - 1) >= 0 && grid[p.first][p.second - 1] == 1) {
                    grid[p.first][p.second - 1] = 2;
                    q.push(make_pair(p.first, p.second - 1));
                };
                
                if ((p.first + 1) < rows && grid[p.first + 1][p.second] == 1) {
                    grid[p.first + 1][p.second] = 2;
                    q.push(make_pair(p.first + 1, p.second));
                };
                
                if ((p.second + 1) < cols && grid[p.first][p.second + 1] == 1) {
                    grid[p.first][p.second + 1] = 2;
                    q.push(make_pair(p.first, p.second + 1));
                };
            };
        };
        
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if (grid[i][j] == 1)
                    return -1;
            }
        }
        
        return days;
    }
};