class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mp;
        for( int i = 0 ; i < nums.size() ; i++ )
        {
            mp[nums[i]] = i;
        }

        for( int i = 0 ; i < nums.size() ; i++ )
        {
            int second_num = target - nums[i];
            cout << nums[i] << " " << second_num << endl;
            if( mp.find( second_num ) != mp.end() && i != mp[second_num] )
            {
                return { i , mp[second_num] };
            }
        }
        return {};
    }
};


/*
1) Brute Force 
TC: O(N^2)
SC: O(1)

2) Two pointer + sorting 
TC: o(nlogn) + o(n) ~= O(nlogn)
SC: O(1)

3) hash map 
TC: O(N)
SC: O(N)

3 4 5 6
0 1 2 3



*/
