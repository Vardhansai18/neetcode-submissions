class Solution {
public:
    void print(vector<int> v)
    {
        for( auto it : v )
        {
            cout << it << " ";
        }
        cout << endl;
    }
    vector<int> productExceptSelf(vector<int>& nums) {

        vector<int> prefix_prod , suffix_prod;
        int prod = 1;
        int size = nums.size();
        vector<int> ans;
        for( int i = 0 ; i < nums.size() ; i++ )
        {
            prefix_prod.push_back( prod );
            prod *= nums[i];
        }
        prod = 1;
        for( int i = nums.size() - 1 ; i >= 0 ; i-- )
        {
            suffix_prod.push_back( prod );
            prod *= nums[i];
        }
        reverse(suffix_prod.begin(),suffix_prod.end());
        print( prefix_prod );
        print( suffix_prod );

        for( int i = 0 ; i < nums.size() ; i++ )
        {
            if( i == 0 )
            {
                ans.push_back( suffix_prod[i] );
            }
            else if( i == size - 1 )
            {
                ans.push_back( prefix_prod[i] );
            }
            else 
            {
                ans.push_back(prefix_prod[i] * suffix_prod[i]);
            }
        }

        return ans;

        

    }
};


/*

1 2 4 6

1.        1        1*2   1*2*4 
2*4*6    4*6        6.    1

*/