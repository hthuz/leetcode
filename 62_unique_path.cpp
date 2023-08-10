

#include "utils.h"
class Solution {
public:
    int uniquePaths(int m, int n) {
        return uniquePaths_dp_space_saving(m,n);
    }
private:
    int uniquePaths_dp(int m, int n) {
        vector<vector<int>> grid;
        for(int i = 0 ; i < m; i++) {
            vector<int> empty_row(n,1);
            grid.push_back(empty_row);
        }

        for(int i = 1; i < m; i++)
            for(int j = 1; j < n; j++)
                grid[i][j] = grid[i - 1][j] + grid[i][j - 1];
        
        return grid[m - 1][n - 1];
    }
    int uniquePaths_dp_space_saving(int m, int n) {

        vector<int> prev(n,1);
        vector<int> cur(n,1);
        vector<int> tmp;

        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n ; j++) {
                cur[j] = prev[j] + cur[j - 1];
            }
            tmp = cur;
            cur = prev;
            prev = tmp;
        }

        return prev[n - 1];
    }
};


int main() 
{
    int res = Solution().uniquePaths(3,7);
    cout << res << endl;
}
