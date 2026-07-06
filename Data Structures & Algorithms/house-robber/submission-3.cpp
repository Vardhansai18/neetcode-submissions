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
        int size = nums.size();
        vector<int> dp( size , -1 );
        return solve( 0 , nums , dp );
    }
};


/*
[2 , 9 , 8 , 3 , 6 ]


2 9 8 3 6
0 1 2 3 4


pick 
nonPick 
*/