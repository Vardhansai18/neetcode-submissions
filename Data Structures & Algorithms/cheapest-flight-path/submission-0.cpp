class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> ans( n + 1 , INT_MAX );
        vector<vector<pair<int,int>>> adj( n + 1 );
        for( auto it : flights )
        {
            int u = it[0] , v = it[1] , w = it[2];
            adj[u].push_back( { v , w } );
        }

        queue<vector<int>> st;
        // stops , node , distance 
        st.push( { 0 , src , 0 } );
        ans[src] = 0;

        while( st.size() )
        {
            auto it = st.front();
            int prev_w = it[2] , prev_node = it[1] , prev_stop = it[0];
            st.pop();
            if( prev_stop > k ) continue;

            for( auto it : adj[prev_node] )
            {
                int curr_node = it.first ,  curr_w = it.second ;
                if( prev_w + curr_w < ans[curr_node] && prev_stop  <= k )
                {
                    ans[curr_node] = prev_w + curr_w;
                    st.push( { prev_stop + 1 , curr_node , prev_w + curr_w  } );
                }
            }
        }

        for( int i = 0 ; i < n ; i++ )
        {
            cout << i << " " << ans[i] << endl;
        }
        return ans[dst] == INT_MAX ? -1 : ans[dst];



        
    }
};
/*

if( stops < k)
*/