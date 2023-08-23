

#include "utils.h"

#define CAPITAL_Z 90
class Solution {
public:
    bool detectCapitalUse(string word) {
        bool all_capital = (*word.begin() <= CAPITAL_Z);
        bool only_first_capital = (*word.begin() <= CAPITAL_Z);
        bool all_not_capital = (*word.begin() > CAPITAL_Z);

        for(string::iterator itr = word.begin() + 1; itr != word.end(); itr++)
        {
            // If it's capital
            if(*itr <= CAPITAL_Z) {
                only_first_capital = false;
                all_not_capital = false;
                continue;
            }
            // If it's not capital
            all_capital = false;
        }

        return all_capital | only_first_capital | all_not_capital;
    }
};

int main()
{
    string word = "FlaG";
    bool ans = Solution().detectCapitalUse(word);
    cout << ans << endl;

}
