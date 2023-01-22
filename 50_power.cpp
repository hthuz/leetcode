
#include <iostream>

using namespace std;

class Solution {
public:
    // Time complexity: log(n)
    double myPow(double x, int n){
        if(n == 0)
            return 1;
        
        double val;
        if(abs(n) % 2 == 0)
        {
            val = myPow(x,n / 2);
            val = val * val;
        }
        if(abs(n) % 2 == 1)
        {
            val = myPow(x,n / 2);
            if(n < 0)
                val = val * val / x;
            else
                val = val * val * x;
        }

        return val;
    }
};


int main()
{
    double val;
    int min = -2147483648;
    int not_min = min + 1;
    val = Solution().myPow(2,not_min);
    cout << val << endl;
}




