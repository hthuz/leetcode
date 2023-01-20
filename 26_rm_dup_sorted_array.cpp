

#include <iostream>
#include <vector>


using namespace std;

void print_vec(vector<int> nums);

class Solution {
public:
    // Time complexity: O(n^2)
    int removeDuplicates(vector<int>& nums){
        vector<int>::iterator itr = nums.begin();

        while((itr + 1) != nums.end())
        {
            if(*(itr + 1) == *itr)
            {
                nums.erase(itr + 1);
                continue;
            }

            itr++;
        }

        return nums.size();
    }

};

int main()
{
    
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    int len;
    print_vec(nums);
    len = Solution().removeDuplicates(nums);

    print_vec(nums);
    cout << len << endl;

}

void print_vec(vector<int> nums)
{
    for(int x : nums)
        cout << x << " ";
    cout << endl;
}

