class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size() , col = matrix[0].size();
        queue<pair<int,int>> q;
        for( int i = 0 ; i < row ; i++ )
        {
            for( int j = 0 ; j < col ; j++ )
            {
                if( matrix[i][j] == 0 )
                {
                    q.push( { i , j } );
                }
            }
        }
        while( q.size() )
        {
            pair<int,int> p = q.front();
            q.pop();

            int zero_x = p.first , zero_y = p.second;

            for( int i = 0 ; i < row ; i++ )
            {
                matrix[i][zero_y] = 0;
            }
            for( int j = 0 ; j < col ; j++ )
            {
                matrix[zero_x][j] = 0;
            }
        }    
    }
};
/*
1) first store the all the zeros indexies in a data structure( queue )
2) iterate over the queue and fill the entire row and column to zeros 


  0 1 2 3 
0
1
2
3
zero = ( 1 , 2 )

for( int i = 0 ; i < row ; i++ ) matrix[i][x];




TC: O(N^2) + O(N^2) ~= O(N^2)
*/
