class Solution {
public:
    int solve(int i, vector<int>& v, vector<int>& dp) {
        if (i < 0) return 0;
        if (dp[i] != -1) return dp[i];

        int pick = v[i] + solve(i - 2, v, dp);
        int nonPick = solve(i - 1, v, dp);

        return dp[i] = max(pick, nonPick);
    }

    int rob(vector<int>& nums) {

        if( nums.size() == 1 ) return nums[0];
       

        vector<int> firstRange, secondRange;
        for(int i = 0; i < nums.size(); i++) {
            if (i != nums.size() - 1) firstRange.push_back(nums[i]); 
            if (i != 0) secondRange.push_back(nums[i]);     
        }
        int n = firstRange.size();

        // Case 1: exclude last house
        vector<int> dp1(n, -1);
        int del_last = solve(n - 1, firstRange, dp1);

        // Case 2: exclude first house
        vector<int> dp2(n, -1);
        int del_first = solve(n - 1, secondRange, dp2);



        cout << del_last << endl;
        cout << del_first << endl;

        return max(del_last, del_first);
    }
};
