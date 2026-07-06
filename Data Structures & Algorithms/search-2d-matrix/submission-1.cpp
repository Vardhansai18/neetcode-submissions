class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        bool result = false;
        for( int i = 0 ; i < matrix.size() ; i++ )
        {
            int low = 0 , high = matrix[0].size() - 1;
            while( low <= high )
            {
                int mid = ( low + high ) / 2;
                if( matrix[i][mid] == target )
                {
                     result = true;
                     break;
                }  
                else if( matrix[i][mid] > target )
                {
                    high = mid - 1;
                }
                else
                {
                    low = mid + 1;
                }
            }
        }
        return result;
    }
};
