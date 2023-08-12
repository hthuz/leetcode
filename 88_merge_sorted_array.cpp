
#include "utils.h"


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        if (!m) {
            nums1 = nums2;
            return;
        }
        if (!n) {
            return;
        }

        int i = 0;
        int j = 0;
        vector<int> res = {};

        for(int c = 0; c < m + n; c++)
        {
            if(j == n || nums1[i] < nums2[j] && i < m) 
                res.push_back(nums1[i++]);
            else
                res.push_back(nums2[j++]);
        }
        nums1 = res;
    }
};


int main() 
{

    // vector<int> nums1 = {1,2,3,0,0,0};
    // vector<int> nums2 = {2,5,6};
    vector<int> nums1 = {2,0};
    vector<int> nums2 = {1};

    Solution().merge(nums1, 1, nums2, 1);
    for(int x : nums1)
        cout << x << " ";

}
