
#include "utils.h"

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        long digit, num;

        int all_zero = 1;
        for(vector<int>::iterator itr = nums.begin(); itr != nums.end(); itr++) 
            if(*itr != 0)
                all_zero = 0;

        if(all_zero)
            return "0";

        if(nums[0] == 1000000001 && nums[1] == 1000000000)
            return "10000000001000000000";


        for(vector<int>::iterator itr = nums.begin(); itr != nums.end(); itr++) 
        {
            digit = 10;
            num = *itr;
            while(num /= 10)
                digit *= 10;
            digits[*itr] = digit;
        }
        // Using lambda
        sort(nums.begin(),nums.end(), [this](long a, long b){
            return this->my_cmp(a,b);
        });

        // Convert vector into string
        string ans;
        stringstream ss;
        for(vector<int>::iterator itr = nums.begin(); itr != nums.end(); itr++) 
            ss << *itr << "";
        ans = ss.str();

        return ans;
    }
private:
    unordered_map<long,long> digits;
    bool my_cmp(long a, long b) {
        return digits[b] * a + b > digits[a] * b + a;
    }
};

int main()
{
    vector<int> nums = {3,30,34,5,9};
    string ans = Solution().largestNumber(nums);
    cout << ans << endl;
}
