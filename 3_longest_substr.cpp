

#include <iostream>
#include <string>

using namespace std;

class Solution{
public:
    // Brute Force method. Time complexity: O(n^3)
    int lengthOfLongestSubstring(string s){
        int i;
        int j;
        int max_len = 0;
        string substr = "";

        for (i = 0; i < s.length(); i++)
        {
            substr += s[i];
            for (j = i + 1;j < s.length(); j++)
            {
                if(!in_string(s[j],substr))
                    substr += s[j];
                else
                    break;
            }
            if(substr.length() > max_len)
                max_len = substr.length();
            substr = "";
        }

        return max_len;
    }
private:
    bool in_string(char c, string s){
        int i;
        for (i = 0; i < s.length(); i++)
        {
            if (c == s[i])
                return true;
        }
        return false;
    }

};



int main()
{
    string s = "abadcbefb";
    int length;
    length = Solution().lengthOfLongestSubstring(s);

    cout << length << endl;

}




