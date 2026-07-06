class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<int>>adj[n+1];
        
        for(int j=0;j<times.size();j++)   // Graph creation
            {
                int u=times[j][0];
                int v=times[j][1];
                int w=times[j][2];
                adj[u].push_back({v,w});
          }

        for( int i = 1 ; i < n ; i++ )
        {
            cout << i << ":" ;
            for( auto it : adj[i] )
            {
                cout << "{" << it[0] << "," << it[1] << "} "; 
            } 
            cout << endl;
        }

        set<pair<int,int>> st;
        st.insert( { 0 , k } );
        vector<int> ans( n + 1 , INT_MAX);
        ans[k] = 0;
        while( st.size() )
        {
            auto [prev_dist , prev_node] =  *(st.begin());
            st.erase( *(st.begin()) );

            for( auto it : adj[prev_node] )
            {
                int curr_node = it[0] , curr_dist = it[1];
                if( prev_dist + curr_dist < ans[curr_node] )
                {
                    ans[curr_node] = prev_dist + curr_dist ;
                    st.insert( { prev_dist + curr_dist  ,  curr_node } );
                }
            } 
        }
        int min_time = 0;
        for( int i = 1 ; i <= n ; i++ )
        {
            cout << i << " " << ans[i] << endl;
            min_time = max( min_time , ans[i] );
        }
        return min_time == INT_MAX ? - 1 : min_time ;
        
    }
};