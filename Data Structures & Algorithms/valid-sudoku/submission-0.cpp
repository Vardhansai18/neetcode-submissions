class Solution {
public:
    bool check_valid_sudoko( vector<vector<char>> board , int i , int j )
    {
        int ele = board[i][j];
        for( int y = 0 ; y < 9 ; y++ )
        {   
            if( y != j )
            {
                if( board[i][y] == ele )
                {
                    return false;
                }
            }
            
        }

        for( int x = 0 ; x < 9 ; x++ )
        {   
            if( x != i )
            {
                if( board[x][j] == ele )
                {
                    return false;
                }
            }
        }

        int start_i = ( i / 3 ) * 3;
        int start_j = ( j / 3 ) * 3;

        for( int x = start_i ; x < start_i + 3 ; x++ )
        {
            for( int y = start_j ; y < start_j + 3 ; y++ )
            {
                if( x != i && y != j )
                {
                    if( ele == board[x][y] )
                    {
                        return false;
                    }
                }

            }
        }
        return true;

    }
    bool isValidSudoku(vector<vector<char>>& board) {
        int row = board.size() , col = board[0].size();
        for( int i = 0 ; i < row ; i++ )
        {
            for( int j = 0 ; j < col ; j++ )
            {
                if( board[i][j] != '.' )
                {
                    if( check_valid_sudoko( board , i , j ) == false )
                    {
                        cout << i << " " << j << endl;
                        return false;
                    }
                }
                
            }
        }
        return true;
    }
};
