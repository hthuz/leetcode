

#include "utils.h"

class Solution {
public:
    int strStr(string haystack, string needle) {
        int index = 0;
        int haystack_size = haystack.size();
        int needle_size = needle.size();
        while(index < haystack_size)
        {
            for(int i = 0; i < needle_size; i++)
            {
                if(haystack[index + i] != needle[i])
                    break;
                if(i == needle_size - 1)
                    return index;
            }
            index++;
        }
        return -1;
    }
};


int main()
{
    string haystack = "leetcode";
    string needle = "leeto";
    int ans = Solution().strStr(haystack, needle);
    cout << ans << endl;

}
