

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    bool isPalindrome(int x){
        vector<int> digits;
        if(x < 0)
            return false;

        while(x)
        {
           digits.push_back(x % 10);
           x /= 10;
        }
        
        while(!digits.empty())
        {
            if(digits.size() == 1)
                return true;
            if(digits.front() != digits.back())
                return false;
            digits.erase(digits.begin());
            digits.pop_back();
        }
        
        return true;
    }
};


int main()
{

    bool val;
    val = Solution().isPalindrome(124421);
    cout << val << endl;
}
