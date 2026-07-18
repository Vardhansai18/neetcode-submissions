class Solution {
public:
    int solve( int i , int j , string s1 , string s2 )
    {
        if( i >= s1.size() || j >= s2.size() )
        {
            return 0;
        }
        if( s1[i] == s2[j] )
        {
            return 1 + solve( i + 1 , j + 1 , s1 , s2 );
        }
        return max( solve( i + 1, j , s1 , s2 ) , solve( i , j + 1 , s1 , s2 ) );
    }

    int longestPalindromeSubseq(string s) {
        string s1 = s , s2 = s;
        reverse(s2.begin(),s2.end());
        return solve( 0 , 0 , s1 , s2 );
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
