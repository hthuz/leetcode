
#include "utils.h"

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
        int Inf = numeric_limits<int>::max();
        vector<vector<int>> lis;
        // Initialize to empty
        for(int i = 0; i < size; i++) {
            vector<int> empty_row(size + 1,0);
            lis.push_back(empty_row);
        }
        nums.push_back(Inf);
        
        // Initialize first row
        for(int j = 0; j < size + 1; j++) 
            if (nums[j] > nums[0])
                lis[0][j] = 1;

        // DP
        for(int i = 1; i < size; i++) {
            for(int j = i; j < size + 1; j++) {
                if(nums[i] >= nums[j])
                    lis[i][j] = lis[i - 1][j];
                else
                    lis[i][j] = max(lis[i - 1][i] + 1,lis[i - 1][j]);
            }
        }

        // print_2dvec(lis);

        return lis[size - 1][size];
    }
};

int main()
{
    vector<int> nums = {10,9,2,5,3,7,101,18};
    // vector<int> nums = {};
    int res = Solution().lengthOfLIS(nums);
    cout << res << endl;

}
