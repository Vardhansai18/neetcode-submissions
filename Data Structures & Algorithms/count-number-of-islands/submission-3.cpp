class Solution {
public:
    int dx[4] = { 0 , 0 , -1 , 1 };
    int dy[4] = { -1 , 1 , 0 , 0 };
    bool check( int new_x , int new_y , vector<vector<char>> &grid )
    {
        if( new_x < 0 || new_y < 0 || new_x >= grid.size() || new_y >= grid[0].size() || grid[new_x][new_y] == '0' )
        {
            return false;
        }
        return true;
    }
    void bfs( vector<vector<char>> &grid , int i , int j )
    {
        queue<pair<int,int>> q;
        q.push( { i , j } );

        while( q.size() )
        {
            pair<int,int> front = q.front();
            int curr_x = front.first , curr_y = front.second;
            q.pop();
            grid[curr_x][curr_y] = '0';

            for( int dir = 0 ; dir < 4 ; dir++ )
            {
                int new_x = curr_x + dx[dir];
                int new_y = curr_y + dy[dir];
                if( check( new_x , new_y , grid ) )
                {
                    q.push( { new_x , new_y } );
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size() , col = grid[0].size();
        int noOfIslands = 0;
        for( int i = 0 ; i < row ; i++ )
        {
            for( int j = 0 ; j < col ; j++ )
            {
                if( grid[i][j] == '1' )
                {
                    noOfIslands++;
                    bfs( grid , i , j ) ;
                }
            }
        }
        return noOfIslands;
    }
};


/*

  0 1 2 
0 
1
2

3*3 matrix :

(1,1) 

left -> ( 1, 0 )
right -> ( 1 , 2 )
up -> ( 0, 1 )
down -> ( 2 , 1 )

dx = { 0 , 0 , -1 , 1 }
dy = ( -1 , 1 , 0 , 0 )


*/
