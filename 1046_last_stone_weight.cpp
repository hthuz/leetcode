
#include "utils.h"


// How to use heap in C++
// Note that pop_heap only moves the top element to the last position
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        make_heap(stones.begin(), stones.end());
        // for(int x : stones)
        //     cout << x << " ";
        // cout << endl;
        // pop_heap(stones.begin(), stones.end());
        // for(int x : stones)
        //     cout << x << " ";
        // cout << endl;

        while(stones.size() != 1)
        {
            int stone1 = stones[0];
            pop_heap(stones.begin(), stones.end());
            stones.pop_back();
            int stone2 = stones[0];
            pop_heap(stones.begin(), stones.end());
            stones.pop_back();
            
            stones.push_back(stone1 - stone2);
            push_heap(stones.begin(), stones.end());
        }
        return stones[0];
    }
};

int main()
{
    vector<int> stones = {1};
    int ans = Solution().lastStoneWeight(stones);
    cout << ans << endl;

}
