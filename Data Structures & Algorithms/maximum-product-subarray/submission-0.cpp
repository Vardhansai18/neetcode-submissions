class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int size = nums.size();
        int max_ans = INT_MIN;
        for( int i = 0 ; i < size ; i++ )
        {
            int mul = 1;
            for( int j = i ; j < size ; j++ )
            {
                mul *= nums[j];
                max_ans = max( max_ans , mul );
            }
        }
        return max_ans;
    }
};

/*
subarrays:
2
2 4
2 4 -3 
2 4 -3 5

4
4 -3
4 -3 5

-3
-3 5

5
*/
