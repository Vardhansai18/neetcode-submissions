class Solution {
public:
    bool checkInclusion(string s1, string s2) {

        map<char,int> m1;
        map<char,int> m2;

        for( auto it : s1 )
        {
            m1[it]++;
        }

        int i = 0 ;
        while( i < s1.size() && i < s2.size() )
        {
            m2[s2[i]]++;
            i++;
        }
        /*
        lecabee
        0123456

        i=3
        i-size

        */
        int size = s1.size();
        if( m1 == m2 ) return true;
        while( i < s2.size() )
        {
            m2[s2[i-size]]--;
            m2[s2[i]]++;
            if( m2[s2[i-size]] == 0 ) m2.erase( s2[i-size]);

            if( m1 == m2 ) return true;
            i++;
        }
        return false;
    }
};
