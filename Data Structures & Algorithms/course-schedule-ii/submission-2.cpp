class Solution {
public:
    bool dfs(vector<int> adj[] , vector<bool> &vis , vector<bool> &pathvisit , int i , stack<int> &st )
    {
        vis[i] = true;
        pathvisit[i] = true;

        for( auto it : adj[i] )
        {
            if( vis[it] == false )
            {
                if( dfs( adj , vis , pathvisit , it , st) ) return true;
            }
            else if( pathvisit[it] )
            {
                return true;
            }
        }
        st.push( i );
        pathvisit[i] = false;
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        stack<int> st;
        for( auto it : prerequisites )
        {
            adj[it[1]].push_back( it[0] );
        }
        vector<bool> vis( numCourses , false );
        vector<bool> pathvisit( numCourses , false );
        vector<int> ans;

        for( int i = 0 ; i < numCourses ; i ++ )
        {
            if( vis[i] == false )
            {
                if( dfs( adj , vis , pathvisit , i , st ) == true ) return {};
            }
        }
        while( st.size() )
        {
            ans.push_back( st.top() );
            st.pop();
        }
        return ans;
        
    }
};


