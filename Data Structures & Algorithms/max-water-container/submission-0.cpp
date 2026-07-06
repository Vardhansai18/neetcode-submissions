class Solution {
public:
    int maxArea(vector<int>& height) {
        int first = 0, last = height.size() - 1;
        int max_area = 0;
        while ( first < last )
        {
            int min_ele = min( height[first] , height[last] );
            int area = min_ele * ( last - first );
            max_area = max( area , max_area );
            if( height[first] < height[last] )    first++;
            else last--;
        }
        return max_area;
    }
};