class Solution {
public:
    void solve( int i , vector<int> &temp , vector<vector<int>> &ans , vector<int> &nums)
    {
        if( i >= nums.size() )
        {
            sort(temp.begin(),temp.end());
            ans.push_back( temp );
            return;
        }
        temp.push_back( nums[i] );
        solve( i + 1 , temp , ans , nums );
        temp.pop_back();
        solve( i + 1 , temp , ans , nums );
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort( nums.begin(), nums.end());
        solve( 0 , temp , ans , nums );

        set<vector<int>> st;
        for( auto it : ans ) st.insert( it );
        vector<vector<int>> fin;
        for( auto it : st )
        {
            fin.push_back( it );
        }
        return fin;
    }
};


/*
1 2 3 

         (1)     ( )
      (1) (1,2) (2). ()
  (1,3) (1) (1,2,3) (1,2) (2,3) (2) (3) ()

*/