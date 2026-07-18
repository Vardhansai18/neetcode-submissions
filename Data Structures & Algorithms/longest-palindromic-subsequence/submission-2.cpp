class Solution {
public:
    int solve( int i , int j , string s1 , string s2 , vector<vector<int>> &dp)
    {
        if( i >= s1.size() || j >= s2.size() )
        {
            return 0;
        }

        if( dp[i][j] != -1 ) return  dp[i][j];

        if( s1[i] == s2[j] )
        {
            return dp[i][j] = 1 + solve( i + 1 , j + 1 , s1 , s2 , dp );
        }
        return dp[i][j] = max( solve( i + 1, j , s1 , s2 , dp ) , solve( i , j + 1 , s1 , s2 , dp ) );
    }

    int longestPalindromeSubseq(string s) {
        string s1 = s , s2 = s;
        reverse(s2.begin(),s2.end());
        int m = s1.size();
        vector<vector<int>> dp( m + 1 , vector<int>(m + 1 ,-1));
        return solve( 0 , 0 , s1 , s2 , dp );
    }
};

/*

 b b a b
b
b
a
b

str1 = bbab
str2 = babb


str1 and str2 
if( str1[i] == str2[i] )
{
    return 1 + solve( i + 1 ,j + 1 );
}
return max( solve(i+1,j) , solve(i,j+1));

*/
