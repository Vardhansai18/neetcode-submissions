class Solution {
public:
    int solve( int i , vector<int> &nums , vector<int> &dp )
    {
        if( i == 0 ) return nums[i];
        if( i < 0 ) return 0;
        
        if( dp[i] != -1 ) return dp[i];

        int Pick = nums[i] + solve( i - 2 , nums , dp);
        int nonPick = solve( i - 1 , nums , dp );
        return dp[i] = max( Pick , nonPick ); 
    }
    int rob(vector<int>& nums) {
        int size = nums.size();

        vector<int> dp( size , -1 );
        return solve( size - 1 , nums , dp );
    }
};


/*
if( n == 0 ) return v[i];

if( i < 0 ) return 0;
pick = v[i] + f( n - 2 );
nonPick = 0 + f( n - 1 );
return max( pick , nonPick );

*/