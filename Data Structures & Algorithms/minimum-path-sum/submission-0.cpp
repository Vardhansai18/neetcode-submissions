class Solution {
public:
    int solve( int i , int j , vector<vector<int>> &grid )
    {
        if( i == grid.size() - 1 && j == grid[0].size() - 1 )
        {
            return grid[i][j];
        }

        if( i >= grid.size() || j >= grid[0].size() ) return INT_MAX;

        int right = solve( i , j + 1 , grid  );
        int down = solve( i + 1 , j , grid );
        return grid[i][j] + min( right , down );

    }
    int minPathSum(vector<vector<int>>& grid) {
        return solve( 0 , 0 , grid );
    }
};