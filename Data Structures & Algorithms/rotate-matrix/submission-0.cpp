class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>> v;
        int row = matrix.size() , col = matrix[0].size();

        for( int i = 0 ; i < row ; i++ )
        {
            vector<int> temp;
            for( int j = col - 1 ; j >= 0 ; j-- )
            {
                cout << matrix[j][i] << " ";
                temp.push_back( matrix[j][i] );
            }
            v.push_back( temp );
            cout << endl;
        }

        for( int i = 0 ; i < row ; i++ )
        {
            for( int j = 0 ; j < col ; j++ )
            {
                matrix[i][j] = v[i][j];
            }
        }
        
    }
};
