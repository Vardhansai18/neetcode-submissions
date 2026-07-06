class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ans;
        int size = nums.size();
        for( int i = 0 ; i < size ; i++ )
        {
            if( nums[i] == target ) 
            {
                ans.push_back( i ); 
                break;
            }
        }

        for( int i = size - 1 ; i >= 0 ; i-- )
        {
            if( nums[i] == target )
            {
                ans.push_back( i ); 
                break;
            } 
        }
        if( size == 0 )
        {
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        if( size == 1 && nums[0] != target )
        {
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        if( ans.size() == 0 ) 
        {
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        } 
        return ans;

        
    }
};