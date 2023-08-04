
#include "utils.h"

class Solution {
public:
    bool isSubsequence(string s, string t) {
        return isSubsequence_iterative(s,t);
    }
private:
    bool isSubsequence_resursive(string s, string t) {

        if(!t.size() && s.size())
            return false;
        if(!t.size() && !s.size())
            return true;

        // Takes substring every time can be time-consuming
        if(s[0] == t[0])
            return isSubsequence_resursive(s.substr(1,s.size() - 1), t.substr(1, t.size() - 1) );
        return isSubsequence_resursive(s, t.substr(1, t.size() - 1));
    }

    bool isSubsequence_iterative(string s, string t) {
        string::iterator s_itr = s.begin();
        string::iterator t_itr = t.begin(); 
        while(s_itr != s.end())
        {
            if (t_itr == t.end())
                return false;
            if(*s_itr == *t_itr)
                s_itr++;
            t_itr++;
        }
        return true;

    }
};

int main()
{
    bool res = Solution().isSubsequence("abc","ahbdc");
    cout << res << endl;

}
