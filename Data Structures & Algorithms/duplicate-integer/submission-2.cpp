class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        map<int,int> m;
        bool flag = false;
        for( auto it : nums )
        {
            m[it]++;
        }
        for( auto it : m )
        {
            int freq = it.second;
            if( freq >= 2 )
            {
                flag = true;
            }
        }
        return flag;
    }
};