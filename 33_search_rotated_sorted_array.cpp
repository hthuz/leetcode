

#include "utils.h"


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int mid;
        
        while(left <= right)
        {
            mid = left + ((right - left) >> 1);
            if(target == nums[mid])
                return mid;
            if(target <= nums[right]) {
                if(nums[mid] > nums[right] || target > nums[mid]) {
                    left = mid + 1;
                    continue;
                }
                right = mid - 1;
                continue;
            }
            // Target is greater than nums[left]
            if(nums[mid] < nums[left] || target < nums[mid]) {
                right = mid - 1;
                continue;
            }
            left = mid + 1;
        }
        return -1;

    }
};


int main()
{
    vector<int> nums = {1};
    int target = 2;
    int ans = Solution().search(nums, target);
    cout << ans << endl;

}
