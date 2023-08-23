

#include "utils.h"

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        int index = 0;
        string ans = "";
        while(1)
        {
            if(index >= strs[0].size())
                return ans;
            char start = strs[0][index];
            for(int j = 1; j < n; j++)
            {
                if(index >= strs[j].size())
                    return ans;
                if(strs[j][index] != start)
                    return ans;
            }
            index++;
            ans = ans + start;
        }
        return ans;
    }
};

int main()
{
    vector<string> strs = {"dflower","flow"};
    string ans = Solution().longestCommonPrefix(strs);
    cout << ans << endl;

}
