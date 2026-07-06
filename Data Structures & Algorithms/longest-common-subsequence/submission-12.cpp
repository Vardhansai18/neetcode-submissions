class Solution {
public:
    int LCS( int i , int j ,  string &s1 , string &s2 )
    {
        if( i >= s1.size() || j >= s2.size() ) return 0;

        if( s1[i] == s2[j] )
        {
            return 1 + LCS( i + 1, j + 1 , s1 , s2 );
        }
        else
        {
            return max( LCS( i + 1, j  , s1 , s2 ) , LCS( i , j + 1 , s1 , s2 ) );
        }
    } 
    int longestCommonSubsequence(string s1, string s2) {
        return LCS( 0 , 0 , s1 , s2 );
    }
};
