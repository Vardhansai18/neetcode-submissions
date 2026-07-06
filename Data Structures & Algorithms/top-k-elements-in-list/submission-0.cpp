class Solution {
public:

    static bool cmp(pair<int,int> p1 , pair<int,int> p2 )
    {
        return p1.first > p2.first;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {

        vector<pair<int,int>> p;
        unordered_map<int,int> m;
        vector<int> ans;
        int i = 0;
        for( auto it : nums )
        {
            m[it]++;
        }
        for( auto it : m )
        {
            p.push_back( { it.second , it.first } );
        }

        sort(p.begin(),p.end(),cmp);

        while( i < k  )
        {
            ans.push_back( p[i].second );
            i++;
        }
        return ans;
        
    }
};
