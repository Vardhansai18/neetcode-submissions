class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        int size = nums.size();
        sort(nums.begin(),nums.end()); 
        vector<vector<int>> ans;
        for( int i = 0 ; i < size - 2 ; i++ )
        {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
                int low = i + 1 , high = size - 1;
                while( low < high )
                {
                    int mid = ( low + high ) / 2;
                    int totalSum = nums[i] + nums[low] + nums[high];

                    if( totalSum == 0 )
                    {
                        // cout << "ans: " << nums[i] << " " << nums[j] << " " << nums[mid] << endl;
                        ans.push_back( { nums[i] , nums[low] , nums[high] } );
                        while( low < high && nums[low] == nums[low+1] ) low++;
                        while( low < high && nums[high] == nums[high-1] ) high--;
                        low++; high--;
                        // break;
                    }
                    else if( totalSum > 0 )
                    {
                        high--;
                    }
                    else
                    {
                        low++;
                    }
                }
        }
        return ans;
        
    }
};


/*

-4 -1 -1 0 1 2 
0   1. 2.3 4.5


*/

