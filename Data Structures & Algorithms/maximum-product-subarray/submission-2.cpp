class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int prod = 1 ;
        int size = nums.size();
        int max_ans = INT_MIN;
        for( int i = 0 ; i < size ; i++ )
        {
            if( nums[i] <= 0 ) 
            {
                prod = 1;
            }
            prod *= nums[i];
            max_ans = max( max_ans , prod );
        }
        prod = 1;
        for( int i = size - 1 ; i >= 0 ; i-- )
        {
            if( nums[i] <= 0 ) 
            {
                prod = 1;
            }
            prod *= nums[i];
            max_ans = max( max_ans , prod );
        }
        return max_ans;

    }
};
