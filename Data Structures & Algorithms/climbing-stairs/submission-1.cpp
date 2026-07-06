class Solution {
public:
    int solve( int i , int n , vector<int> &dp)
    {
        if( i >= n ) return i == n;
        if( dp[i] != -1 ) return dp[i];
        return dp[i] = solve( i + 1 , n , dp ) + solve( i + 2 , n ,dp ); 
    }
    int climbStairs(int n) {
        vector<int> dp( n, -1);
        return solve( 0 , n , dp );
    }
};

/*
3 
1 1 1
1 2
2 1


    fun(n)
 fun(n-1) fun(n-2)

3 -> 2 , 1
2 -> 1 , 0
1 -> 0 

          0
        (1 2) 
    (2 3) (3 4)
  (3,5)     ( 2, )
*/