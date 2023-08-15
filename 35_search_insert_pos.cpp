
#include "utils.h"


// Given solution:  Find the first element that is equal to or greater than the target
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size();
        int mid;
        while(left != right)
        {
            mid = (left + right) / 2;
            if(target > nums[mid])
            {
                if (target > nums[right - 1])
                    return right;
                left = mid;
                continue;
            }
            if(target < nums[mid])
            {
                if (target < nums[left])
                    return left;
                right = mid;
                continue;
            }
            return mid;
        }
        return -1;
    }
};

int main()
{

    vector<int> nums = {1,2,3,5};
    int target = 0;
    int res = Solution().searchInsert(nums, target);
    cout << res << endl;

}
