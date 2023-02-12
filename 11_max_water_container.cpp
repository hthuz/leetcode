
#include "lib.h"

class Solution{
public:
    int maxArea(vector<int>& height){
        int i = 0;
        int j = height.size() - 1;
        int area = 0;

        while(i < j)
        {
            if(height[i] < height[j])
            {
               area = max(area, height[i] * (j - i));
               i++;
            }else
            {
                area = max(area, height[j] * (j - i));
                j--;
            }
        }

        return area;
    }
};

int main()
{
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    int result;
    result = Solution().maxArea(height);
    cout << result;

}
