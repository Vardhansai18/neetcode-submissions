class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        stack<vector<int>> st;
        sort( intervals.begin(),intervals.end());

        for( int i = 0 ; i < intervals.size() ; i++ )
        {

            if( st.size() == 0 )
            {
                st.push( {intervals[i][0] , intervals[i][1]} );
            }
            else
            {
                vector<int> top = st.top();
                int start_x = top[0] , end_x = top[1];
                int start_y = intervals[i][0] , end_y = intervals[i][1];
                if( end_x >= start_y )
                {
                    st.pop();
                    st.push( { start_x , max(end_x , end_y) } );
                }
                else
                {
                    st.push( intervals[i] );
                }
            }
        }

        vector<vector<int>> ans;
        while( st.size() )
        {
            ans.push_back( st.top() );
            st.pop();
        }
        reverse( ans.begin() ,ans.end() );
        return ans;
        
    }
};

/*
[1,3]
[1,5]    

start_x , end_x
start_y , end_y 

if( end_x <= start_y )
{
    { start_x , end_y }
}

*/