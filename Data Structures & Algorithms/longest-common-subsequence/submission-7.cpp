class Solution {
public:
    int LCS( int i , int j , string &s1 , string &s2 , vector<vector<int>> &dp)
    {
        if( i == 0 || j == 0 ) return 0;
        if( dp[i][j] != -1 ) return dp[i][j];
        if( s1[i-1] == s2[j-1] ) 
        {
            return dp[i][j] = 1 + LCS( i - 1 , j - 1 , s1 , s2 , dp );
        }
        else
        {
            return dp[i][j] = max( LCS( i - 1 , j , s1 , s2 , dp ) , LCS( i , j - 1 , s1 , s2 , dp ) );
        }
    }
    int longestCommonSubsequence(string s1, string s2) {

        int m = s1.size() , n = s2.size();
        vector<vector<int>> dp( m + 1 , vector<int>(n + 1 ,-1));

        for( int i = 0 ; i < m ; i ++ ) dp[i][0] = 0;
        for( int i = 0 ; i < n ; i ++ ) dp[0][i] = 0;

        for( int i = 1 ; i <= m ; i++ )
        {
            for( int j = 1 ; j <= n ; j++ )
            {
                if( s1[i-1] == s2[j-1] ) 
                {
                    dp[i][j] = 1 + dp[i-1][j-1] ;
                }
                else
                {
                    dp[i][j] = max( dp[i-1][j] , dp[i][j-1] );
                }
            }
        } 

        return dp[m][n];
    }
};

/*

s1 = cat 
s2 = crabt

  0 1 2 3  4
0
1
2
3




cat
 i

ccat
 j


if( s1[i] == s2[j] ) 
{
    return 1 + solve( i + 1 , j + 1 , s1 , s2 );
}
else
{
    return solve( i + 1 , j + 1 , s1 , s2 );
}
*/
