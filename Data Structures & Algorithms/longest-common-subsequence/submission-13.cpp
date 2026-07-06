class Solution {
public:

    int LCS( int i , int j ,  string &s1 , string &s2 , vector<vector<int>> &dp)
    {
        if( i >= s1.size() || j >= s2.size() ) return 0;

        if( dp[i][j] != -1 ) return dp[i][j];

        if( s1[i] == s2[j] )
        {
            return dp[i][j] = 1 + LCS( i + 1, j + 1 , s1 , s2, dp );
        }
        else
        {
            return dp[i][j] = max( LCS( i + 1, j  , s1 , s2 , dp) , LCS( i , j + 1 , s1 , s2 , dp ) );
        }
    } 
    int longestCommonSubsequence(string s1, string s2) {
        int m = s1.size() , n = s2.size();
        vector<vector<int>> dp( m , vector<int>(n,-1));
        return LCS( 0 , 0 , s1 , s2 , dp );
    }
};
