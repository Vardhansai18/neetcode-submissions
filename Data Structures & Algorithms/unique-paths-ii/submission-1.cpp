class Solution {
public:
    bool isvalid( int i , int j , vector<vector<int>>& grid )
    {
        if( i >= grid.size() || j >= grid[0].size() || grid[i][j] == 1 ) 
        {
            return false;
        }
        return true;
    }
    int solve( int i , int j , vector<vector<int>>& grid , vector<vector<int>>& dp)
    {
        if( i == grid.size() - 1 && j == grid[0].size() - 1 ) 
        {
            return 1;
        }

        if(dp[i][j] != -1 ) return dp[i][j];
        int right = 0 , left = 0;
        if( isvalid( i , j + 1 , grid ) ) 
        {
            right = solve( i , j + 1 , grid , dp );
        }
        if( isvalid( i + 1 , j , grid ) ) 
        {
            left = solve( i + 1 , j , grid , dp );
        }
        return dp[i][j] = right + left; 
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int row = obstacleGrid.size() , col = obstacleGrid[0].size();
        vector<vector<int>> dp( row , vector<int>(col,-1));
        return solve( 0 , 0 , obstacleGrid , dp );
        
    }
};
/*
  0 1 2
0 0 0 0
1 0 0 0
2 0 1 0 
*/