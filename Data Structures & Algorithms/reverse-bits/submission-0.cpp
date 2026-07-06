class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int i = 1;
        int ans = 0;
        while( n )
        {
            if( n & 1 )
            {
                ans += (1<<(32-i));
            }
            i++;
            n = n >> 1;
        }
        return ans;
        
    }
};
