class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for( auto it : nums )
        {
            pq.push( it );
            if( pq.size() > k ) pq.pop();
        }
        // while( pq.size() )
        // {
        //     cout << pq.top() << endl;
        //     // pq.pop();
        // }
        return pq.top();
        
    }
};




// 4
// 5
