class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> indegree( n+1 , 0 );
        vector<int> outdegree( n+1 , 0 );
        for( auto it : trust )
        {
            int x = it[0] , y = it[1] ;
            indegree[y]++;
            outdegree[x]++;
        }
        for( int i = 1 ; i <= n ; i++ )
        {
            if( indegree[i] == n - 1 && outdegree[i] == 0 )
            {
                return i;
            } 
        }
        return -1;
    }
};

/*

1 : 3
2 : 3 
3 : 0
4 : 3


3 : outgoint edge 0 

*/