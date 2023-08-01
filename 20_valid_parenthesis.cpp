

#include "utils.h"
#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int len = s.length();

        for(int i = 0; i < len; i++)
        {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
            {
                st.push(s[i]);
                continue;
            }
            // Input is "}"
            if(st.empty())
                return false;
            if(s[i] == ')' && st.top() != '(')
                return false;
            if(s[i] == ']' && st.top() != '[')
                return false;
            if(s[i] == '}' && st.top() != '{')
                return false;
            st.pop();
        }

        // Input is "{"
        return st.empty();
    }
};

int main()
{
    bool val = Solution().isValid("]");
    cout << val << endl;

}
