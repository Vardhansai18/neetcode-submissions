class Solution {
public:
    int solve( int i , int j , string &s1 , string &s2, vector<vector<int>> &dp)
    {
        if( i < 0 ) return j + 1;
        if( j < 0 ) return i + 1;

        if( dp[i][j] != -1 ) return dp[i][j];

        if( s1[i] == s2[j] )
        {
            return solve( i - 1, j - 1 , s1 , s2 , dp );
        } 

        int insert = 1 + solve( i - 1 , j , s1 , s2 , dp );
        int del = 1 + solve( i , j - 1 , s1 , s2 , dp );
        int replace = 1 + solve( i - 1 , j - 1 , s1 , s2 , dp );
        return dp[i][j] = min( insert, min( del , replace) );
    }
    int minDistance(string word1, string word2) {
        int size_1 = word1.size() , size_2 = word2.size();
        vector<vector<int>> dp(size_1, vector<int>(size_2, -1));
        return solve( size_1 - 1  , size_2 - 1 , word1 , word2 , dp );
    }
};
