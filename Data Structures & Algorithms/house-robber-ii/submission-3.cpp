class Solution {
public:

    int solve( int i , vector<int> nums , vector<int> &dp)
    {
        if( i >= nums.size() )
        {
            return 0;
        }
        if( dp[i] != -1 ) return dp[i];
        int pick = nums[i] + solve( i + 2 , nums , dp );
        int nonpick = solve( i + 1 , nums , dp );
        return dp[i] = max( pick , nonpick );
    }

    int rob(vector<int>& nums) {

        if( nums.size() == 1 ) return nums[0];

        int size = nums.size();
        vector<int> dp1( size , -1 );
        vector<int> dp2( size , -1 );

        vector<int> v1, v2;

        for( int i = 1 ; i < nums.size() ; i++ )
        {
            v1.push_back( nums[i] );
        }
        for( int i = 0 ; i < nums.size() - 1 ; i++ )
        {
            v2.push_back( nums[i] );
        }

        int first_skip = solve( 0 , v1 , dp1 );
        int last_skip = solve( 0 , v2 , dp2 );
        return max( first_skip , last_skip );

    }
};
