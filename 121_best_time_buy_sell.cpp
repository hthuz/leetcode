
#include "utils.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxprofit = 0;
        int minprice = 1e5;
        for(int price: prices) {
            maxprofit = max(maxprofit, price - minprice);
            minprice = min(minprice, price);
        }
        return maxprofit;
    }
private:
    vector<int> prices;

    // Try every division of prices.
    int maxProfit_naive(vector<int>& prices) {
        int n = prices.size(); int cur_min, cur_max;
        int max_profit = 0;
        for(int i = 1; i < n; i ++){ 
            cur_min = *min_element(prices.begin(),prices.begin() + i);
            cur_max = *max_element(prices.begin() + i, prices.end());
            max_profit = max(max_profit, cur_max - cur_min);
        }
        return max_profit;
    }

    int maxProfit_recursive(vector<int>& prices) {
        this->prices = prices;
        // If negative, return 0
        return max(0, _maxProfit(0, prices.size() - 1, *prices.begin(), *(prices.end() - 1)));
    }

    int _maxProfit(int i,int j,int cur_min, int cur_max) {
        if (i < j)
            return max(_maxProfit(i + 1, j, min(cur_min,prices[i + 1]), cur_max), \
                      _maxProfit(i, j - 1, cur_min, max(cur_max, prices[j - 1])));
        return cur_max - cur_min;
    }
};

int main()
{
    // vector<int> prices = {7,6,5,4,3,1};
    vector<int> prices = {7,1,5,3};
    int res = Solution().maxProfit(prices);
    cout << res << endl;

}
