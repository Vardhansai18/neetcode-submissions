class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        queue<pair<int,int>> q;
        for( int i = 0 ; i < row ; i++ )
        {
            for( int j = 0 ; j < col ; j++ )
            {
               if( matrix[i][j] == 0 ) q.push( { i , j } );
            } 
        }
        cout << q.size() << endl;
        while( q.size() )
        {
            pair<int,int> p = q.front();
            q.pop();
            int i =  p.first , j = p.second;
            for( int x = 0 ; x < col ; x++ )
            {
                matrix[i][x] = 0;
            }
            for( int x = 0 ; x < row ; x++ )
            {
                matrix[x][j] = 0;
            }
        }
        // return matrix;
    }
};
/*
 0 1 2 3 
0
1
2


2,3

(2,0) (2,1) (2,2) (2,3)


row = 2 
col = 3 
for( int x = 0 ; x < col ; x++ )

for( in)

*/