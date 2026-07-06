class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {

        int size = nums.size();
        map<int,int> m;
        for( int i = 0 ; i < size ; i++ )
        {
            if( m.find(nums[i]) != m.end() && abs(i - m[nums[i]]) <= k )
            {
                return true;
            }
            else
            {
                m[nums[i]] = i;
            }
        }
        return false;
        
    }
};


/*
nums = [1,2,3,1], k = 3
        0 1 2 3
    
map : 
1 : 0 
2 : 1
3 : 3 
1 : 
*/