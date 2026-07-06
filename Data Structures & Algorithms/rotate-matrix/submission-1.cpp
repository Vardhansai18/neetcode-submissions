class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int row = matrix.size() , col = matrix[0].size();
        for( int i = 0 ; i < col ; i++ )
        {
            for( int j = 0 ; j < i ; j++ )
            {
                cout << i << j << " ";
                swap( matrix[i][j] , matrix[j][i] );
            }
            cout << endl;
        }

        for( int i = 0 ; i < row ; i++ )
        {
            reverse( matrix[i].begin(), matrix[i].end() ); 
        }
        
    }
};
