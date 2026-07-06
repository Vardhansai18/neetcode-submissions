class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int cnt = 0;
        vector<vector<int>> output;
        sort( intervals.begin(),intervals.end());

        for( int i = 0 ; i < intervals.size() ; i++ )
        {

            if( output.size() == 0 )
            {
                output.push_back( {intervals[i][0] , intervals[i][1]} );
            }
            else
            {
                vector<int> top = output.back();
                int start_x = top[0] , end_x = top[1];
                int start_y = intervals[i][0] , end_y = intervals[i][1];
                if( end_x > start_y )
                {
                    // output.back()[1] = max(end_x , end_y);
                    cnt++;
                    output.back()[1] = min(end_x , end_y);

                }
                else
                {
                    output.push_back( intervals[i] );
                }
            }
        }
        return cnt; 
        
    }
};