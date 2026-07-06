class Solution {
public:


    int solve( int i , vector<int> &cost , vector<int> &dp)
    {
        if( i >= cost.size() )
        {
            return 0;
        }

        if( dp[i] != -1 ) return dp[i];
        int firstStep = cost[i] + solve( i + 1 , cost , dp );
        int secondStep = INT_MAX;
        if( i + 1 <= cost.size()  )
        {
            secondStep = cost[i] + solve( i + 2 , cost , dp );
        }
        return dp[i] = min( firstStep , secondStep );
    }
    int minCostClimbingStairs(vector<int>& cost) {

        // cout << solve( 0 , cost ) << endl;
        // cout << solve( 1 , cost ) << endl;
        int size = cost.size();
        vector<int> dp1( size , -1 );
        vector<int> dp2( size , -1 );
        return min( solve( 0 , cost ,dp1 ) , solve(1,cost,dp2) );
        
    }
};

/*
0 1 2

1 < 1
*/
