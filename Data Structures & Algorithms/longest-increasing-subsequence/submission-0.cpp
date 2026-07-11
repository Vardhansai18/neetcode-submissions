int solve( int i ,  vector<int> &nums , int prev )
{
  if( i == nums.size() )
  {
      return 0;
  }
  int pick = 0;
  if( prev == -1 || nums[prev] < nums[i] )
  {
    pick = 1 + solve( i + 1 , nums , i );
  }
  int nonpick = solve( i + 1 , nums , prev );
  return max( pick , nonpick );
}
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
      return solve( 0 , nums, -1);
    }
};

/*
ex: [9,1,4,2,3,3,7]

9 1 4 2 3 3 7
0 1 2 3 4 5 6

*/
