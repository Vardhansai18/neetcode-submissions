class Solution {
public:
    vector<vector<int>> ans;
    void solve( int idx , vector<int> temp , vector<int> nums , int sum , int target )
    {
        if( sum > target ) return;
        if( idx >= nums.size() )
        {
            if( sum == target )
            {
                ans.push_back( temp );
            }
            return;
        }

        temp.push_back( nums[idx] );
        sum += nums[idx];
        solve( idx , temp , nums , sum , target );
        temp.pop_back();
        sum -= nums[idx];
        solve( idx + 1 , temp , nums ,  sum , target ); 
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> temp;
        solve( 0 , temp , nums , 0 , target );
        return ans;
    }
};


