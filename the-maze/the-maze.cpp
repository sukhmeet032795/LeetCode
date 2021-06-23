class Solution {
    vector<vector<int>> dirs;
public:
    Solution() {
        dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    }
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int currX = start[0], currY = start[1];
        int destX = destination[0], destY = destination[1];
        
        vector<vector<bool>> visited(maze.size(), vector<bool>(maze[0].size()));
        
        return helper(maze, currX, currY, destX, destY, visited);
    }
    
    bool helper(vector<vector<int>>& maze, int currX, int currY, int destX, int destY, vector<vector<bool>>& visited) {
        if (currX < 0 || currX >= maze.size() || currY < 0 || currY >= maze[0].size() || visited[currX][currY]) return false;
        if (currX == destX && currY == destY) return true;
                
        visited[currX][currY] = true;
        
        for (vector<int>& dir : dirs) {
            int newX = currX + dir[0];
            int newY = currY + dir[1];
            while (newX >= 0 && newX < maze.size() && newY >= 0 && newY < maze[0].size() && maze[newX][newY] != 1) {
                newX += dir[0];
                newY += dir[1];
            }
            newX -= dir[0];
            newY -= dir[1];
            if (helper(maze, newX, newY, destX, destY, visited)) return true;
        }
        return false;
    }
};