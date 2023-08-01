
#include <iostream>
using namespace std;

class Solution {
public:
    int findComplement(int num) {
        int sum = 0;
        long times = 1;
        int original_num = num;
        while(num)
        {
            sum = sum + times;
            times = times * 2;
            num = num / 2;
        }

        return sum - original_num;
    }
};


int main()
{
    int val = Solution().findComplement(2147483647);
    // int val = Solution().findComplement(8);
    cout << val << endl;
}
