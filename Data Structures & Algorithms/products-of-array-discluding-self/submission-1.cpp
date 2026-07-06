class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> ans(size,0);
        int prod = 1;
        for( int i = 0 ; i < nums.size() ; i++ )
        {
            ans[i] = prod;
            prod = prod * nums[i];
        }
        prod = 1;
        for( int i = nums.size() - 1 ; i>= 0 ; i-- )
        {
            ans[i] *= prod;
            prod = prod * nums[i];
        }
        return ans;


    }
};
/*

1      2   4     6
1      1   1*2  1*2*4  
2*4*6 4*6  6    1


*/