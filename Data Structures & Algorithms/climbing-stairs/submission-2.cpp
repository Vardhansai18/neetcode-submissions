class Solution {
public:
    int climbStairs(int n) {

        vector<int> dp( n + 1 , -1 );
        if( n == 1 || n == 2 ) return n;
        dp[1] = 1; dp[2] = 2;

        for( int i = 3 ; i <= n ; i++ )
        {
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
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




  n = 3
  1 -> 1
  2 -> 2 
  3 -> 3
  4 -> 5 
  5 -> 8

  
*/