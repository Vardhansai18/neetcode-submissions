class Solution {
public:
    int LCS( int i , int j ,  string &s1 , string &s2 , vector<vector<int>> &dp)
    {
        if( i <= 0 || j <= 0 ) return 0;

        if( s1[i-1] == s2[j-1] )
        {
            return dp[i][j] = 1 + LCS( i - 1, j - 1 , s1 , s2 , dp );
        }
        else
        {
            return dp[i][j] = max( LCS( i - 1, j  , s1 , s2 , dp) , LCS( i , j - 1 , s1 , s2 , dp ) );
        }
    } 
    int longestCommonSubsequence(string s1, string s2) {
        int m = s1.size() , n = s2.size();
        vector<vector<int>> dp( m + 1 , vector<int>(n + 1 ,-1));
        return LCS( s1.size() , s2.size()  , s1 , s2 , dp );
    }
};
