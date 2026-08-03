class Solution {
public:
    int solve( int m , int n )
    {
        if( m == 0 && n == 0 )
        {
            return 1;
        }
        if( m < 0 || n < 0 ) return 0;

        int right = solve( m , n - 1 );
        int down = solve( m - 1 , n );
        return right + down ;
    }
    int uniquePaths(int m, int n) {
        return solve( m - 1 , n - 1 );
    }
};
