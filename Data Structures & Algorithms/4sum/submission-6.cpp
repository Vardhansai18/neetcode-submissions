class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {


        set<vector<int>> st;
        vector<vector<int>> ans;
        int size = nums.size();
        
        // if( size == 4 ) 
        // {
        //     for()
        // }
        sort( nums.begin(), nums.end() );
        for( int i = 0 ; i < size - 3 ; i++ )
        {
            for( int j = i + 1 ; j < size - 2 ; j++ )
            {
                for( int k = j + 1 ; k < size - 1 ; k++ )
                {
                    for( int l = k + 1 ; l < size ; l++ )
                    {
                        // cout << nums[i] << " " << nums[j] << " " << nums[k] << " " << nums[l] << endl;
                        // long long int sum = nums[i] + nums[j] + nums[k] + nums[l];
                        long long sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];
                        // cout << "sum: " << sum << endl;
                        if( sum == target )
                        {
                            st.insert( { nums[i] , nums[j] , nums[k] , nums[l] } );
                        }
                    }
                }
            }
        }

        for( auto it : st )
        {
            ans.push_back( it );
        }
        return ans;
    }
};


/*
-3 0 1 2 3 3 
 0 1 2 3 4 5 

 size = 6

*/

