

#include "utils.h"

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>>dp(m,vector<int>(n,0));
        int ans = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == '1') {
                    if(i == 0 || j == 0)
                        dp[i][j] = 1;
                    else
                        dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                    ans = max(ans,dp[i][j]);
                }
            }
        }

        cout << endl;
        print_2dvec(dp);

        return ans * ans;
    }
};


int main()
{
    int m = 4;
    int n = 5;
    vector<vector<char>> matrix(m, vector<char>(n,0));
    matrix[0][0] = '1';
    matrix[1][0] = '1';
    matrix[2][0] = '1';
    matrix[3][0] = '1';
    matrix[2][1] = '1';
    matrix[0][2] = '1';
    matrix[1][2] = '1';
    matrix[2][2] = '1';
    matrix[1][3] = '1';
    matrix[2][3] = '1';
    matrix[3][3] = '1';
    matrix[1][4] = '1';
    matrix[2][4] = '1';
    print_2dvec(matrix);

    int ans = Solution().maximalSquare(matrix);
    cout << ans << endl;


}
