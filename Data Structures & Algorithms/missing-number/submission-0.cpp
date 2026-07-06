class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int missNum = 0;
        for( int i = 0 ; i <= n ; i++ )
        {
            missNum ^= i;
        }
        for( int i = 0 ; i < n ; i++ )
        {
            missNum ^= nums[i];
        }
        return missNum;
    }
};
