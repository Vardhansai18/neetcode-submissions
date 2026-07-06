class Solution {
public:
    bool checkValidString(string s) {

        stack<int> lp;
        stack<int> star;

        for( int i = 0 ; i < s.size() ; i++ )
        {
            if( s[i] == '(' )
            {
                lp.push( i );
            }
            else if( s[i] == '*' )
            {
                star.push( i );
            }
            else
            {
                if( lp.size() ) lp.pop();
                else if( star.size() ) star.pop();
                else return false;
            }
        }
        
        while( lp.size() && star.size() )
        {
            cout << "lp.top :" << lp.top() << " " << "star : " << star.top() << endl;
            if( lp.top() > star.top() ) return false;
            lp.pop(); 
            star.pop();
        }
        return lp.size() == 0 ? true : false;

    }
};
