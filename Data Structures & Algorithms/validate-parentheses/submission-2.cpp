class Solution {
public:
    bool check( char top , char s )
    {
        if( top == '(' )
        {
            return s == ')';
        }
        else if( top == '{' )
        {
            return s == '}';
        }
        else if( top == '[' )
        {
            return s == ']';
        } 
        return false;
    }
    bool isValid(string s) {
        stack<char> st;
        for( int i = 0 ; i < s.size() ; i++ )
        {
            if( st.size() == 0 )
            {
                st.push( s[i] );
            }
            else
            {
                if( check( st.top() , s[i] ) )
                {
                    st.pop();
                }
                else
                {
                    st.push( s[i] );
                }
            }
        }
        return st.size() == 0 ;
        
    }
};
