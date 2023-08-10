

#include "utils.h"


class Solution {
public:
    int lengthOfLastWord(string s) {
        int count = 0;
        bool meet_letter = false;
        int n = s.size();
        for(int i = n - 1; i >= 0; i--)
        {
            if(s[i] == ' ' && !meet_letter)
                continue;
            meet_letter = true;
            if(s[i] == ' ')
                break;
            count++;
        }
        return count;

    }
};

int main() 
{
    int res = Solution().lengthOfLastWord(" fly tsf  adsf  ");
    cout << res << endl;

}
