
#include "utils.h"
#include <unordered_map>    

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> count;
        int max_num = 0;
        int max_elt;
        for(int x : nums) {
            count[x]++;
        }

        for(auto x : count) {
            if (x.second > max_num) {
                max_num = x.second;
                max_elt = x.first;
            }
        }

        return max_elt;
    }
};

int main()
{
    vector<int> nums = {3,2,3};
    int res = Solution().majorityElement(nums);
    cout << res << endl;

}
