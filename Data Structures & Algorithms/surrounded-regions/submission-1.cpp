class Solution {
public:
    vector<int> dir = { -1 , 0 , 1 , 0 , -1 };
    void bfs( vector<vector<char>>& board , int row , int col )
    {
        queue<pair<int,int>> q;
        q.push( { row , col }  );
        board[row][col] = '#';
        while( q.size() )
        {
            pair<int,int> front = q.front();
            int r = front.first , c = front.second;
            q.pop();
            for( int i = 0 ; i < dir.size() - 1 ; i ++ )
            {
                int new_x = dir[i] + r;
                int new_y = dir[i+1] + c;
                if( new_x >= 0 && new_y >= 0 && new_x < board.size() && new_y < board[0].size() &&
                    board[new_x][new_y] == 'O' )
                    {
                        board[new_x][new_y] = '#';
                        q.push( { new_x,new_y} );
                    }
            } 
        } 
    }
    void solve(vector<vector<char>>& board) {
        int row = board.size() , col = board[0].size();
        vector<pair<int,int>> corner_zeros;
        for( int i = 0 ; i < row ; i++ )
        {
            for( int j = 0 ; j < col ; j++ )
            {
                if( i == 0 || j == 0 || i == row - 1  || j == col - 1 )
                {
                    if( board[i][j] == 'O' ) corner_zeros.push_back( { i , j } );
                }
            }
        }
        for( auto it : corner_zeros )
        {
            cout << it.first << " " << it.second << endl;
            bfs( board , it.first , it.second );
        }

        for( int i = 0 ; i < row ; i ++ )
        {
            for( int j = 0 ; j < col ; j++ )
            {
                if( board[i][j] == '#' ) board[i][j] = 'O';
                else if( board[i][j] == 'O' ) board[i][j] = 'X';
            }
        }
    }
};


/*
  0 1 2 3 4
0
1
2
3
4
*/