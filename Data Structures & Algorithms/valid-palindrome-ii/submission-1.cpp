class Solution {
public:

    bool check_palindrome( string s , int low ,  int high )
    {
        while( low < high )
        {
            if( s[low] != s[high] )
            {
                return false;
            }
            else if( s[low] == s[high] )
            {
                low++;high--;
            }
        }
        return true;
    }
    bool validPalindrome(string s) {


        int low = 0 , high = s.size() - 1 ;


        while( low < high )
        {
            if( s[low] == s[high] )
            {
                low++;high--;
            }
            else
            {
                bool s1 = check_palindrome( s , low , high-1 );
                bool s2 = check_palindrome( s , low+1 , high );
                if( s1 || s2 ) return true;
                else return false;
            }
        }
        return true;
    }
};


/*
abbda
01234

1) i++ ; j-- ; 
   i = 1 ; j = 3

3) 


if( i > j ) return true;

if( s[i] == s[j] ) return check( i-- , j-- ); 
else return check(i,j--) || check(i++,j);

*/