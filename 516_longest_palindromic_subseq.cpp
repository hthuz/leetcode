
#include "utils.h"

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int size = s.size();
        vector<vector<int>> dp(size, vector<int>(size, 0));
        
        // Initialization
        for(int i = 0; i < size; i++)
            dp[i][i] = 1;

        for(int n = size - 2; n >= 0; n--)
        {
            for(int m = n + 1; m < size; m++)
            {
                dp[n][m] = max(dp[n + 1][m], dp[n][m - 1]);
                if (s[n] == s[m])
                    dp[n][m] = max(dp[n][m], 2 + dp[n + 1][m - 1]);
            }
        }
        // print_2dvec(dp);
        return dp[0][size - 1];
    }
};

int main()
{
    string s = "bbbab";
    int ans = Solution().longestPalindromeSubseq(s);
    cout << ans << endl;


}
