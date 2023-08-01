
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = (1 + n) * n / 2;
        for(vector<int>::iterator itr = nums.begin(); itr < nums.end(); itr++)
            sum -= *itr;
        cout << sum << endl;
        return sum;

    }
};


int main()
{
    vector<int> nums = {0,1};
    int val = Solution().missingNumber(nums);

}
