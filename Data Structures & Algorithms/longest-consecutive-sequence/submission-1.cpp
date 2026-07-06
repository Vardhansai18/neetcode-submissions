class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if( nums.size() == 0 ) return 0;
        unordered_set<int> st;
        for(auto &it : nums )
        {
            st.insert( it);
        }
        int ans = 0;
        for( int i = 0 ; i < nums.size() ; i++ )
        {
            int x = nums[i];
            if( st.find( x - 1 ) == st.end() )
            {
                int cnt = 1;
                while(st.find( x + 1 ) != st.end())
                {
                    x = x + 1;
                    cnt = cnt + 1;
                }   
                ans = max( ans, cnt);
            }
        }
        return ans;
    }
};