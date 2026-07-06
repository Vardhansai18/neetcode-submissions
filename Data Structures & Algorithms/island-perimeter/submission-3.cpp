class Solution {
public:
    bool check( int new_x , int new_y , vector<vector<int>> &grid )
    {
        if( new_x < 0 || new_y < 0 || new_x >= grid.size() || new_y >= grid[0].size() || grid[new_x][new_y] == 0 )
        {
            return true;
        }
        return false;
    }
    int boundCntfun( int curr_x , int curr_y , vector<vector<int>>& grid) 
    {
        int dx[4] = { 0 , 0 , -1 , 1 };
        int dy[4] = { -1 , 1 , 0 , 0 };
        int boundCnt = 0;
        for( int dir = 0 ; dir < 4 ; dir++ )
        {
            int new_x = curr_x + dx[dir];
            int new_y = curr_y + dy[dir];
            if( check( new_x , new_y , grid ) )
            {
                boundCnt++;
            }
        }
        return boundCnt;
    }
    int islandPerimeter(vector<vector<int>>& grid) {

        // vector<pair<int,int>> ones;
        int row = grid.size() , col = grid[0].size();
        int ans = 0;
        for( int i = 0 ; i < row ; i++ )
        {
            for( int j = 0 ; j < col ; j++ )
            {
                if( grid[i][j] == 1 )
                {
                    int boundCnt = boundCntfun( i , j , grid );
                    ans += boundCnt;
                }
            }
        }
        return ans;
        
    }
};