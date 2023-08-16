
#include "utils.h"

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> jewel_set;
        int ans = 0;
        for(string::iterator itr = jewels.begin(); itr != jewels.end(); itr++)
            jewel_set.insert(*itr);
        for(string::iterator itr = stones.begin(); itr != stones.end(); itr++)
            if (jewel_set.find(*itr) != jewel_set.end())
                ans++;
        return ans;
    }
};

int main()
{
    string jewels = "z";
    string stones = "ZZ";
    int ans = Solution().numJewelsInStones(jewels, stones);
    cout << ans << endl;

}
