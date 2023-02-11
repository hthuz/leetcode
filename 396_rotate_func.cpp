
#include <iostream>
#include <vector>
#include "lib.h"
using namespace std;


class Solution {
public:
    int maxRotateFunction(vector<int>& nums){
        int k;
        int max;
        int val = 0;
        int n = nums.size();
        int nums_sum = 0;
        vector<int> results = {};

        for(int i = 0; i < n; i++)
            nums_sum += nums[i];


        for(k = 0; k < n; k++)
        {
            if(k == 0){
                for(int i = 0; i < n; i++) 
                    val += i * nums[i];
                max = val;
            }else{
                val = results.back() + nums_sum - n * nums[(n - k)];
                if (val > max)
                    max = val;
            }
            results.push_back(val);
        }

        return max;
       }
};


int main()
{
    vector<int> nums = {4,3,2,6};
    int result;

    result = Solution().maxRotateFunction(nums);

    cout << result << endl;
}

