class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {

        int size = nums.size();
        set<vector<int>> st;
        sort( nums.begin(),nums.end());
        vector<vector<int>> ans;
        for( int i = 0 ; i < size - 3 ; i++ )
        {
            for( int j = i + 1 ; j < size - 2 ; j++ )
            {
                int low = j + 1 , high = nums.size() - 1;
                long long int Twosum = (long long)nums[i] + nums[j];
                long long int targetSum = (long long)target - Twosum;

                while( low < high )
                {
                    long long int  sum = (long long)nums[low] + nums[high] ;
                    if( sum == targetSum )
                    {
                        st.insert( { nums[i] , nums[j] , nums[low] , nums[high] } );
                        low++;
                        high--;
                    }
                    else if( sum > targetSum )
                    {
                        high--;
                    }
                    else
                    {
                        low++;
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

// -3 0 1 2 3 3 

