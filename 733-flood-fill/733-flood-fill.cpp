class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        
        if (image[sr][sc] == color)
            return image;
        
        queue<pair<int, int>> q;
        q.push(make_pair(sr, sc));
        int startColor = image[sr][sc], rows = image.size(), cols = image[0].size();
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
};