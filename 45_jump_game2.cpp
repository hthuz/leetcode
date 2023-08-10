

#include "utils.h"

class Solution {
public:
    int jump(vector<int>& nums) {

        int n = nums.size();
        vector<int> jp(n, 10001);

        jp[0] = 0;
        for(int i = 0; i < n; i++) 
            for(int j = 1; j <= nums[i]; j++) 
                if(i + j < n)
                    jp[i + j] = min(jp[i + j], jp[i] + 1);


        return jp[n - 1];
    }
};


int main() {
    vector<int> nums = {2,3,0,1,4};
    int res = Solution().jump(nums);
    cout << res << endl;

}
