
#include "utils.h"

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {

        vector<int> nums(amount + 1, amount + 1);
        nums[0] = 0;
        int n = coins.size();

        for(int i = 1; i <= amount; i++){
            for(int j = 0; j < n; j++)
                if(i - coins[j] >= 0)
                    nums[i] = min(nums[i], nums[i - coins[j]] + 1);
        }
        // cout << nums.size() << endl;
        // for(int x : nums)
        //     cout << x << " ";
        // cout << endl;
        
        return nums[amount] == amount + 1 ? -1 : nums[amount];
    }
};

int main() 
{
    vector<int> coins = {5};
    int amount = 11;
    int res = Solution().coinChange(coins, amount);
    cout << res << endl;
}
