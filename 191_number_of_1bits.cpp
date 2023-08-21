
#include "utils.h"
#include <stdint.h>

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        cout << n << endl;
        for(uint32_t i = 0; i < 32; i++)
        {
            cout << i << " " << (1 << i) << endl;
            if (n & (1 << i))
                ans++;
        }
        return ans;
    }
};


int main()
{
    uint32_t n = 00000000000000000000000000000110;
    int ans = Solution().hammingWeight(n);
    cout << ans << endl;
    

}
