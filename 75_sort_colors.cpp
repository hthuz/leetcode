

#include "utils.h"

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int accumulate[] = {0, 0, 0};
        for(int num : nums)
            accumulate[num] += 1;

        int i = 0;
        for(int j = 0; j < 3; j++) 
            for(int k = 0; k < accumulate[j]; k++)
                nums[i++] = j;
    }
};


int main()
{
    vector<int> nums = {2,0,1};
    Solution().sortColors(nums);
    for(int num : nums)
        cout << num << " ";

}
