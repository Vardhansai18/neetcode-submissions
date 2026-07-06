class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {

        vector<pair<int,int>> water;
        int row = grid.size() , col = grid[0].size();
        for( int i = 0 ; i < row ; i++ )
        {
            for( int j = 0 ; j < col ; j++ )
            {
                if( grid[i][j] == 1 )
                {
                    water.push_back( { i , j } );
                }
            }
        }

        int cnt = 0;

        vector<int> dx = { -1 , 0 , 1 , 0 };
        vector<int> dy = { 0 , -1 , 0 , 1 };

//  (1,1)

//  1,0 ( 0 , -1 )
//  0,1 ( -1 , 0 )
//  1,2 ( 0 , 1)
//  2,1 ( 1 , 0 )

        for( auto it : water )
        {
            cout << "water: " << it.first << "," << it.second << endl; 
            for( int i = 0 ; i < 4 ; i++ )
            {
                int x = dx[i] + it.first;
                int y = dy[i] + it.second;

                if( x >= 0 && y >= 0 && x < row && y < col )
                {
                    if( grid[x][y] == 1 )  continue;
                    else cnt++;
                }
                else
                {
                    cout << x << " " << y << endl;
                    cnt++;
                }
            }
        }
        return cnt;
        
    }
};

/*
OBJ_PREFIX + SHA1(VirtualServerName + "@" + ConnectivityProfileName)


   0 1 2 3 
 0
 1
 2
 3



 



( 1 , 2 ) -> 

-1,0
0,-1
1,0
0,1

*/

