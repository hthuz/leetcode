
#include "utils.h"

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        // int val_num = 0;
        int head = 0, tail = n - 1;
        while(head <= tail)
        {
            if(nums[head] == val)
            {
                n--;
                // Swap
                nums[head] = nums[tail];
                tail--;
                continue;
            }
            head++;
        }

        return n;
    }
};

int main()
{
    vector<int> nums = {0,1,2,2,3,0,4,2};
    int val = 2;
    int ans = Solution().removeElement(nums, val);
    cout << ans << endl;
    for(int x : nums)
        cout << x << " ";
    cout << endl;

    return 0;
}
