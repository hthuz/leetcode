
#include <iostream>
#include <vector>
#include "lib.h"

using namespace std;


class Solution{
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> result;
        vector<vector<int>> upper_result;
        vector<int> upper_level;
        vector<int> cur_level = {};
        int i;

        // Base situation
        if(numRows == 1)
        {
            result = {{1}};
            return result;
        }
        if(numRows == 2)
        {
            result = {{1},{1,1}};
            return result;
        }
        
        // Get previouw result
        upper_result = generate(numRows - 1);
        upper_level = upper_result[upper_result.size() - 1];

        // Set up the new row
        cur_level.push_back(1);
        for(i = 0; i <numRows - 2; i++)
        {
            cur_level.push_back(upper_level[i] + upper_level[i + 1]);
        }
        cur_level.push_back(1);

        // Return the result  
        result = upper_result;
        result.push_back(cur_level);
        return result;

    }
};


int main()
{
    vector<vector<int>> result;
    result = Solution().generate(1);
    print_2dvec(result);

}
