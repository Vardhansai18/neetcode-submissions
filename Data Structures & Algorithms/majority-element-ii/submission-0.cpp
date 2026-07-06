class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {


        int occ = nums.size() / 3;
        map<int,int> m;
        vector<int> ans;
        for( auto it : nums ) m[it]++;

        for( auto it : m )
        {
            if( it.second > occ )
            {
                ans.push_back( it.first );
            }
        }       
        return ans;
    }
};