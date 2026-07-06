class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(),digits.end());
        int rem = 1;
        for( int i = 0 ; i < digits.size() ; i++ )
        {
            digits[i] += rem;
            int num = digits[i];
            digits[i] = num % 10;
            rem = num / 10; 
        }
        while( rem )
        {
            digits.push_back( rem % 10 );
            rem = rem / 10;
        }
        reverse(digits.begin(),digits.end());
        return digits;
    }
};
