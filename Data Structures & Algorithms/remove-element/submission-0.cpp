class Solution {
public:
    int removeElement(vector<int>& nums, int val) {

        int ans = 0;
        vector<int> temp ;
        for( auto it : nums )
        {
            if( it != val )
            {
                ans++;
                temp.push_back( it );
            }
        }

        for( int i = 0 ; i < ans ; i++ )
        {
            nums[i] = temp[i];
        }
        return ans;
    }
};