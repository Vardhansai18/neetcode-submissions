class Solution {
public:
    int dx[4] = { 0 , 0 , -1 , 1 };
    int dy[4] = { -1 , 1 , 0 , 0 };
    bool check( int new_x , int new_y , vector<vector<int>> &grid )
    {
        if( new_x < 0 || new_y < 0 || new_x >= grid.size() || new_y >= grid[0].size() || grid[new_x][new_y] == 0 )
        {
            return false;
        }
        return true;
    }
    void bfs( vector<vector<int>> &grid , int i , int j , int &maxAreaIsland)
    {
        int areaIsland = 0 ;
        queue<pair<int,int>> q;
        q.push( { i , j } );
        grid[i][j] = 0;
        while( q.size() )
        {
            pair<int,int> front = q.front();
            areaIsland++;
            int curr_x = front.first , curr_y = front.second;
            cout << curr_x << "  " << curr_y << endl;
            q.pop();
            for( int dir = 0 ; dir < 4 ; dir++ )
            {
                int new_x = curr_x + dx[dir];
                int new_y = curr_y + dy[dir];
                if( check( new_x , new_y , grid ) )
                {
                    grid[new_x][new_y] = 0;
                    q.push( { new_x , new_y } );
                }
            }
        }
        maxAreaIsland = max( maxAreaIsland , areaIsland  );
        cout << areaIsland << endl;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {

        int row = grid.size() , col = grid[0].size();
        int maxAreaIsland = 0;
        for( int i = 0 ; i < row ; i++ )
        {
            for( int j = 0 ; j < col ; j++ )
            {
                if( grid[i][j] == 1 )
                {
                    cout << "(i:j)" << i << " " << j << endl;
                    bfs( grid , i , j , maxAreaIsland ) ;
                }
            }
        }
        return maxAreaIsland;
        
    }
};
