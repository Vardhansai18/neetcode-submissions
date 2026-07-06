class Solution {
public:
    int search(vector<int>& nums, int target) {

        int low = 0 , high = nums.size() - 1;
        while( low <= high )
        {
            int mid = ( low + high ) / 2;
            if( nums[mid] == target ) return mid;
            else if( nums[low] <= nums[mid] )
            {
                if( nums[low] <= target && target <= nums[mid] )
                {
                    high = mid;
                }
                else
                {
                    low = mid + 1;
                }
            }
            else
            {
                if( nums[mid] <= target && target <= nums[high] )
                {
                    low = mid;
                }
                else
                {
                    high = mid - 1;
                }
            }
        }
        return -1;
    }
};


// 3 4 5 6 1 2 
// 0 1 2 3 4 5


// low high mid
// 0.    5.   2


// if( nums[low] < nums[high] && nums[low] < target < nums[high] )
// {
//     high = mid;
// }
// else
// {
//     low = mid + 1;
// }

// if( nums)

