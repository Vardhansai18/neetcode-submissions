#include <bits/stdc++.h>
class Solution {
public:
    int dp[101][101][201];
    bool solve( int i , int j , int k , string &s1 , string &s2 , string &s3 )
    {
        if( i >= s1.size() && j >= s2.size() && k >= s3.size() )
        {
          return true;
        }
        if( k >= s3.size() ) return false;

        if( dp[i][j][k] != -1 ) return dp[i][j][k];
        bool check = false;
        if( s1[i] == s3[k] )
        {
            check = solve( i + 1 , j  , k + 1 , s1 , s2 , s3 );
        }
        if( s2[j] == s3[k] )
        {
            check = solve( i , j + 1 , k + 1  , s1 , s2 , s3 );
        }
        return dp[i][j][k] = check;
    }
    bool isInterleave(string s1, string s2, string s3) {

        memset(dp, -1, sizeof(dp));
        return solve( 0 , 0 , 0 ,  s1 , s2 , s3 );
    }
};


/*
s3 = aab bbcd bddef
k

s1 = aabddef
i
s2 = bbcd
j

if( i > s1.size() && j > s2.size() && k > s3.size() ) return true;

if( k > s3.size() ) 


if( s1[i] == s2[j] ) 
{
    i+1,j+1;
}
if s1[i] == s3[k]
  i+1 , k+1






*/
