class Solution {
public:
    int LCS( int i , int j , string &s1 , string &s2 , vector<vector<int>> &dp)
    {
        if( i < 0 || j < 0 ) return 0;
        if( dp[i][j] != -1 ) return dp[i][j];
        if( s1[i] == s2[j] ) 
        {
            return dp[i][j] = 1 + LCS( i - 1 , j - 1 , s1 , s2 , dp );
        }
        else
        {
            return dp[i][j] = max( LCS( i - 1 , j , s1 , s2 , dp ) , LCS( i , j - 1 , s1 , s2 , dp ) );
        }
    }
    int longestCommonSubsequence(string text1, string text2) {

        int m = text1.size() , n = text2.size();
        vector<vector<int>> dp( m , vector<int>(n,-1));
        return LCS( m - 1 , n - 1 , text1 , text2 , dp );
    }
};

/*
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
