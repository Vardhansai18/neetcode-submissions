class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> m1;
        unordered_map<char,int> m2;

        for( auto it : s )
        {
            m1[it]++;
        }
        for( auto it : t )
        {
            m2[it]++;
        }

        for( char x = 'a' ; x <= 'z' ; x++ )
        {
            if( m1[x] != m2[x] )
            {
                return false;
            }
        }
        return true;

        
    }
};
