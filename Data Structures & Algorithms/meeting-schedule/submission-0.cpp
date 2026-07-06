/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        vector<pair<int,int>> v;
        for (auto &interval : intervals) 
        {
             v.push_back({interval.start, interval.end});
        }
        sort( v.begin(),v.end() );

        int i = 0 , j = 1;
        while( j < v.size() )
        {
            int start_a = v[i].first , end_a = v[i].second;
            int start_b = v[j].first , end_b = v[j].second;

            if( end_a > start_b ) return false;
            i++;j++;
        }
        return true;
        
    }
};
