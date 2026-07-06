class Solution {
public:
    bool isHappy(int n) {

        set<int> st;
        st.insert( n );
        while( n != 1 )
        {
                int num = n;
                int sum = 0;
                while( num )
                {
                    int rem = num%10;
                    sum = sum + pow(rem,2);
                    num = num / 10;
                }
                n = sum;
                if( st.find( sum ) == st.end() ) st.insert( sum );
                else break;
            
        }
        return n == 1 ? true : false;
        
    }
};

// 19 = 1 + 81 = 82
// 82 = 64 + 4 = 68
// 68 = 36 + 64 = 100
// 100 = 1

// num = 19

// 1) store in set (19)
// while()
// 2) sum of square digit (19)
//  if check the sum in the set if yes break
//  else store in set( sum )






