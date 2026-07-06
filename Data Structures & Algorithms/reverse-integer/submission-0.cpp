class Solution {
public:
    int reverse(int x) {

        long int sum = 0;

        while( x )
        {
            int rem = x % 10 ;
            int ques = x / 10 ;
            sum = sum * 10 + rem;
            x = x / 10 ;
        }
        return sum < INT_MAX-1 && sum > INT_MIN ? sum : 0 ;
    }
};

/*
4000 + 300 + 20 + 1


n = 1234

rem = 4 
ques = 123 

sum = sum * 10 + rem 
sum = 4

sum = 40 + 3 = 43 

sum = 430 + 2 = 432 

sum = 4320 + 1 = 4321 

*/