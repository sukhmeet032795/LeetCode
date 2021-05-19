class Solution {
    
    int max_gold=INT_MIN;
    public:
    
    void dfs(vector<vector<int>>& grid,int i,int j,int maxCollection,int r,int c){
        
        if(i<0 || i>=r || j<0 || j>=c || grid[i][j]==0){
            return;
        }

        int g=grid[i][j];
        grid[i][j]=0;
        max_gold=max(max_gold,maxCollection+g);
        dfs(grid,i+1,j,maxCollection+g,r,c);
        dfs(grid,i-1,j,maxCollection+g,r,c);
        dfs(grid,i,j+1,maxCollection+g,r,c);
        dfs(grid,i,j-1,maxCollection+g,r,c);
        grid[i][j]=g;
    };

    int getMaximumGold(vector<vector<int>>& grid) {
        
        int r=grid.size();
        int c=grid[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(grid[i][j]!=0){
                    dfs(grid,i,j,0,r,c);
                }
            }
        }
        return max_gold;
    };
};