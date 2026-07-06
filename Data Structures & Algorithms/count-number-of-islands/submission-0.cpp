class Solution {
public:
    vector<int> dx = { 0 , -1 , 1 , 0 };
    vector<int> dy = { -1 , 0 , 0 , 1 };
    void bfs( vector<vector<char>> &grid , int r ,  int c )
    {
        int row_size = grid.size() , col_size = grid[0].size();
        queue<pair<int,int>> q;

        q.push( { r , c } );
        while( q.size() )
        {
            int size = q.size();
            pair<int,int> front = q.front();
            int x = front.first , y = front.second;
            q.pop();
            for( int i = 0 ; i < dx.size() ; i++ )
            {
                int new_x = dx[i] + x  , new_y = dy[i] + y;
                // cout << "new_x :" << new_x << " " << "new_y :" << new_y << endl;
                if( new_x >= 0 && new_y >= 0 && new_x < row_size && new_y < col_size
                    && grid[new_x][new_y] == '1' )
                    {
                        // cout << "x" << endl;
                        grid[new_x][new_y] = '0';
                        q.push( { new_x , new_y } );
                    }
            }
        }
        // print( grid );
        // cout << endl;
    }
    void print( vector<vector<char>> &grid )
    {
        for( int i = 0 ; i < grid.size() ; i++ )
        {
            for( int j = 0 ; j < grid[0].size() ; j++ )
            {
                cout << grid[i][j] << " ";
            }
            cout << endl;
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        for( int i = 0 ; i < grid.size() ; i++ )
        {
            for( int j = 0 ; j < grid[0].size() ; j++ )
            {
                if( grid[i][j] == '1' )
                {
                    islands++;
                    bfs( grid , i , j );
                    print( grid );
                    cout << endl;
                } 
            }
        }
        return islands;
        
    }
};
