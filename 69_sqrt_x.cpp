
#include "utils.h"


// In sorted array [0,1,2,3,4,5,7,...x], find the largetst integer i that such i^2 <= x;
class Solution {
public:
    int mySqrt(int x) {
        int left = 0;
        int right = x;
        long mid;
        int ans;
        // int step = 0;
        while(left <= right)
        {
            mid = (left + right) >> 1;
            // cout << "Step " << step++ << ": " << "left: " << left << " mid: " << mid << " right: " << right << endl;
            if(mid * mid > x) {
                right = mid - 1;
            }
            else {
                ans = mid;
                left = mid + 1;
            }
        }
        return ans;
    }
};

int main()
{
    int res = Solution().mySqrt(0);
    cout << res << endl;
    
}
