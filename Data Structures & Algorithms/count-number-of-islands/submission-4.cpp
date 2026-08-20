class Solution {
public:

/*
  0 1 2 
0
1
2 
(1,1)
left. up right down
(0,-1) (-1,0) (0,1) (1,0)
0 -1 0 1 0
0  1 2 3 4 
*/
    vector<int> dir = { 0 , -1 , 0 , 1 , 0 };
    bool valid( int x , int y , vector<vector<char>> &grid )
    {
        if( x < 0 || y < 0 || x >= grid.size() || y >= grid[0].size() || grid[x][y] == '0' )
        {
            return false;
        }
        return true;
    }
    void bfs( int i , int j , vector<vector<char>> &grid )
    {
        queue<pair<int,int>> q;
        q.push( { i , j } );
        grid[i][j] = '0';

        while( q.size() )
        {
            int x = q.front().first , y = q.front().second;
            q.pop();
            for( int k = 0 ; k < 4 ; k++ )
            {
                int new_x = x + dir[k];
                int new_y = y + dir[k+1];
                if( valid( new_x , new_y , grid ) )
                {
                    grid[new_x][new_y] = '0';
                    q.push( { new_x , new_y } );
                } 
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        // Initialzing the variables 
        int numOfIslands = 0 ;
        int row = grid.size() , col = grid[0].size();

        // Iterating through the matrix  
        for( int i = 0 ; i < row ; i++ )
        {
            for( int j = 0 ; j < col ; j++ )
            {
                if( grid[i][j] == '1' )
                {
                    bfs( i , j , grid );
                    numOfIslands++;
                }
            }
        }
        return numOfIslands;
    }
};


/*
// Process 
1) iterate throught the grid 
2) if the grid[i][j] == 1 do bfs on the matrix and fill all the adjacent with 0 s and increase the counter 
3) once all the grid[i][j] == 1, are iterated then return the counter 
*/
