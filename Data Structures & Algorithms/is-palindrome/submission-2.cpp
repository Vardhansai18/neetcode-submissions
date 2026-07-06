class Solution {
public:
    bool isPalindrome(string s) {

        int first_ptr = 0 , last_ptr = s.size() - 1;
        while( first_ptr < last_ptr )
        {
            while( first_ptr < last_ptr && (!isalpha(s[first_ptr]) && !isdigit(s[first_ptr])) )
            {
                first_ptr++;
            }
            while( last_ptr > first_ptr && (!isalpha(s[last_ptr]) && !isdigit(s[last_ptr])) )
            {
                last_ptr--;
            }
            cout << first_ptr << " " << last_ptr << endl;
            char first = toupper(s[first_ptr]),  last = toupper(s[last_ptr]);

            if( first != last ) return false;
            first_ptr++;last_ptr--;
        }
        return true;
    }
};

/*

Time complexity : O(N)
Space Complexity : O(1)
*/
