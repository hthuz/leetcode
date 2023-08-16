
#include "utils.h"


// IB(n) = max(max(k, IB(k)) * max(n - k ,IB(n - k)))  for k in range [1, n / 2]
// 
//
class Solution {
public:
    int integerBreak(int n) {
        int dp[n + 1];
        dp[0] = 0;
        dp[1] = 1;

        for(int i = 2; i < n + 1; i++)
        {
            dp[i] = 0;

            for(int k = 1; k <= i / 2; k++)
            {
                // dp[i] = max(dp[i], dp[k] * dp[i - k]);
                // dp[i] = max(dp[i], k * (i - k));
                dp[i] = max(dp[i], max(dp[k], k) * max(dp[i - k], i - k));
            }
        }
        for(int x : dp)
            cout << x << " ";
        cout << endl;

        return dp[n];
    }
};

int main()
{
    int ans = Solution().integerBreak(10);
    cout << ans << endl;

}
