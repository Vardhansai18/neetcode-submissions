class Solution {
public:
    int LCS( int i , int j ,  string &s1 , string &s2 )
    {
        if( i <= 0 || j <= 0 ) return 0;

        if( s1[i-1] == s2[j-1] )
        {
            return 1 + LCS( i - 1, j - 1 , s1 , s2 );
        }
        else
        {
            return max( LCS( i - 1, j  , s1 , s2 ) , LCS( i , j - 1 , s1 , s2 ) );
        }
    } 
    int longestCommonSubsequence(string s1, string s2) {
        return LCS( s1.size() , s2.size()  , s1 , s2 );
    }
};
