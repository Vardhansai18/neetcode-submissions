class Solution {
public:
    void dfs( vector<int> adj[] , vector<bool> &vis , int x )
    {
        vis[x] = true;
        for( auto it : adj[x] )
        {
            if( vis[it] == false )
            {
                dfs( adj , vis , it );
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        int cnt = 0 ;
        for( auto it : edges )
        {
            adj[it[0]].push_back( it[1] );
            adj[it[1]].push_back( it[0] );
        }
        // for( int i = 0 ; i < n ; i++ )
        // {
        //     cout << i << " : ";
        //     for( auto it : adj[i] )
        //     {
        //         cout << it << " ";
        //     }
        //     cout << endl;
        // }
        vector<bool> vis(n,false);
        for( int i = 0 ; i < n ; i++ )
        {
            if( vis[i] == false )
            {
                cnt++;
                dfs( adj , vis , i );
            } 

        }
        return cnt;

    }
};
