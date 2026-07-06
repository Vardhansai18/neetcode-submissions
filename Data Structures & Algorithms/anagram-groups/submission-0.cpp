class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string,vector<string>> mp;
        for( auto it : strs )
        {
            string s = it;
            sort(s.begin(),s.end());
            mp[s].push_back( it );
        }

        for( auto it : mp )
        {
            string s = it.first;
            vector<string> v = it.second;
            sort( v.begin(),v.end());
            ans.push_back( v );
        }
        return ans;
        
    }
};
