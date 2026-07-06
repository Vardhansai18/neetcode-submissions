class Solution {
public:
    void print(vector<int> v )
    {
        for( auto it : v )
        {
            cout << it << " ";
        }
        return;
    }
    int maxProfit(vector<int>& prices) {
        int size = prices.size();
        vector<int> min_buy(size);
        vector<int> max_sell(size);
        int minn = INT_MAX;
        int maxx = INT_MIN;
        for( int i = 0 ;i < size;i++)
        {
            minn = min( minn , prices[i]);
            min_buy[i] = minn;
        }
        for( int i = size-1 ;i >=0 ;i--)
        {
            maxx = max( maxx , prices[i] );
            max_sell[i] = maxx;
        }

        print(min_buy);
        cout << endl;
        print(max_sell);


        int ans = 0;
        for( int i = 0 ; i < size ; i++ )
        {
            ans = max( ans , abs( min_buy[i] - max_sell[i] ));
        }
        return ans;
        
    }
};



/*
    10 1  5  6  7  1
max 10 7  7  7  7  1
min 10 1  1. 1.  1  1



    10  8  7. 5.  2
max 10. 8  7 5  2
min 10.  8. 7  5. 2

*/