                 // 0.   1.  2.  3.  4
vector<int> dir_x = { 0 , -1 , 0 , 1 }; 
vector<int> dir_y = { -1 , 0 , 1 , 0 };
bool check( int new_x , int new_y , vector<vector<int>> &grid)
{
    if( new_x >= 0 && new_y >= 0 && new_x < grid.size() && new_y < grid[0].size() && 
        grid[new_x][new_y] == 1
    )
    {
        return true;
    }
    return false;
}
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        queue<pair<int,int>> q;
        int fresh = 0;
        for( int i = 0 ; i < grid.size() ; i++ )
        {
            for( int j = 0 ; j < grid[0].size() ; j++ )
            {
                if( grid[i][j] == 2 ) q.push( { i , j } );
                else if( grid[i][j] == 1 ) fresh++;
            }
        }
        if( fresh == 0 ) return 0;
        int minutes = 0;
        while( q.size() > 0 && fresh > 0 )
        {
            int size = q.size();
            minutes++;
            while( size-- )
            {
                pair<int,int> front = q.front();
                q.pop();
                int x = front.first,  y = front.second;
                for( int i = 0 ; i < dir_x.size() ; i++ )
                {
                    int new_x = x + dir_x[i];
                    int new_y = y + dir_y[i];
                    if( check(new_x , new_y , grid) )
                    {
                        fresh--;
                        grid[new_x][new_y] = 2;
                        q.push( { new_x,new_y } );
                    }
                }

            }

        }
        return fresh == 0 ? minutes : -1;
    }
};

/*
  0 1 2
0
1
2

0,-1
-1,0
0,1
1,0

0 -1 0 1 0

*/