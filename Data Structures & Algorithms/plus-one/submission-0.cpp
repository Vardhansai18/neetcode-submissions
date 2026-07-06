class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(),digits.end());
        int rem = 1;
        for( int i = 0 ; i < digits.size() ; i++ )
        {
            digits[i] += rem;
            int num = digits[i];
            cout << "num: " << num << " ";
            digits[i] = num % 10;
            cout << "ques: " << num / 10 << " ";
            rem = num / 10; 
            cout << "rem: " << rem % 10 << " ";
            cout << endl;
        }
        cout << rem << endl;
        while( rem )
        {
            digits.push_back( rem % 10 );
            rem = rem / 10;
        }
        reverse(digits.begin(),digits.end());
        return digits;
    }
};
