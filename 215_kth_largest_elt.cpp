
#include "utils.h"
#include <asm-generic/errno.h>


// Quick select
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
        int size = nums.size();
        int pivot = nums[0];
        vector<int> smaller = {};
        vector<int> larger = {};
        int pivot_num = 1;

        for(int i = 1; i < size; i++)
        {
            if(nums[i] < pivot)
                smaller.push_back(nums[i]);
            if(nums[i] == pivot)
                pivot_num++;
            if(nums[i] > pivot)
                larger.push_back(nums[i]);
        }

        if(k > larger.size() && k <= larger.size() + pivot_num)
            return pivot;
        if(k <= larger.size())
            return findKthLargest(larger, k);
        return findKthLargest(smaller, k - larger.size() - pivot_num);
        
    }
};

int main()
{
    vector<int> nums = {1};
    int k = 1;
    int ans = Solution().findKthLargest(nums, k);
    cout << ans << endl;

}
