class Solution {
    int dfs(vector<vector<int>>& grid, int i, int j) {
        
        if (i >= grid.size() || j >= grid[0].size() || 
            i < 0 || j < 0 || grid[i][j] == 0 )
            return 0;
        
        int count  = 1;
        grid[i][j] = 0;
        
        count += dfs(grid, i+1, j);
        count += dfs(grid, i-1, j);
        count += dfs(grid, i, j-1);
        count += dfs(grid, i, j+1);
        
        return count;
    }
    
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int maxVal = 0;
        for (int i=0; i<grid.size(); i++)
            for (int j=0; j<grid[0].size(); j++) 
                if (grid[i][j])
                    maxVal = max(maxVal, dfs(grid,i,j));
        
        return maxVal;
        
    }
};
