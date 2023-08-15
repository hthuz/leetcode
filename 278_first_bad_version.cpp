

#include "utils.h"

int bad = 2;

bool isBadVersion(int version) {
    return (version >= bad);
}

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1;
        int right = n;
        int mid, ans;
        while(left <= right)
        {
            // Avoid integer overflow.
            // mid = (left + right) >> 1;
            mid = ((right - left) >> 1) + left;
            if(isBadVersion(mid)) {
                ans = mid;
                right = mid - 1;
            }
            else
                left = mid + 1;
        }
        
        return ans;
    }
};


int main()
{
    int n = 5;
    int ans = Solution().firstBadVersion(n);
    cout << ans << endl;

}
