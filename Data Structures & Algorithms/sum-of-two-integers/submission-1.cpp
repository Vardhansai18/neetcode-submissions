class Solution {
public:
    int getSum(int a, int b) {

        while( b )
        {
            int temp = (a&b) << 1;
            a = a ^ b;
            b = temp;
        }
        return a;
    }
};

// 16 8 4 2 1

//  1 1 1 1 - 15 
//  1 0 1 0 - 10
//  1 1 0 0 1


// // 1 1 0 0 1 

/*
               8 4 2 1 
           a = 1 1 1 1 - 15
           b = 1 0 1 0 - 10

a&b << 1 = 1 0 1 0 0  b
a ^ b    = 0 0 1 0 1  a
---------------------
a&b << 1 = 0 1 0 0 0  b
a ^ b    = 1 0 0 0 1  a
---------------------
a&b << 1 = 0 0 0 0 0  b
a ^ b    = 1 1 0 0 1  a
*/