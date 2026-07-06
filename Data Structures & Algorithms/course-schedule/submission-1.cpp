class Solution {
public:
    bool dfs( vector<int> adj[], vector<bool> &vis , vector<bool> &path_visit , int x )
    {
        vis[x] = true;
        path_visit[x] = true;
        for( auto it : adj[x] )
        {
            if( vis[it] == false )
            {
                if( dfs(adj , vis , path_visit , it)) return true;
            }
            else if( path_visit[it] )
            {
                return true;
            }
        }
        path_visit[x] = false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        int size = prerequisites.size();
        for( auto it : prerequisites )
        {
            vector<int> temp = it;
            adj[temp[1]].push_back( temp[0] );
        }

        for( int i = 0 ; i < numCourses ; i++ )
        {
            cout << i << ":";
            for( auto it : adj[i] )
            {
                cout << it << " ";
            }
            cout << endl;
        }
        vector<bool> vis( numCourses , false );
        vector<bool> path_visit( numCourses , false );

        for( int i = 0 ; i < numCourses ; i++ )
        {
            if( vis[i] == false )
            {
                if(dfs(adj,vis,path_visit,i)) return false;
            }
        }
        return true;
    }
};
