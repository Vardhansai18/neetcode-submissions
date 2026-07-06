class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {


        map<char,int> hash;
        for( int i = 0 ; i < order.size() ; i++ )
        {
            hash[order[i]] = i;
        }
        for( int i = 0 ; i < words.size() - 1; i++ )
        {
            string a = words[i] , b = words[i+1];

            int j = 0 ;
            int min_size = min( a.size() , b.size() );
            while( j < min_size && a[i] == b[i] )
            {
                j++;
            }
            if( j < min_size )
            {
                if( hash[a[j]] > hash[b[j]] ) return false;

            }
            else
            {
                if( a.size() > b.size() ) return false;
            } 
        }
        return true;
        
    }
};

/*

["neetcode","neet"]


// 1) iterate through words

a = neetcode b = neet

min_size = 4

j = 0 -> 
if( hash[a[j]] > hash[b[j] ]) return false;

else if( a.size() > b.size() ) return fals;e

*/