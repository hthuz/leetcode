
#include <iostream>
#include <vector>

using namespace std;
void print_2dvec(vector<vector<int>>& vec);
void print_vec(vector<int> nums);

class Solution{
public:
    vector<vector<int>> subsets(vector<int>& nums){
        vector<vector<int>> result; // Final result
        vector<int> subset;  // One subset of nums
        int num_subsets;     // Number of subsets of nums
        int bitmap;          // From 0000 to 1000(num_subsets) as an
                             // example
        vector<int> bits;    // bits set to one.
        
        num_subsets = 1;
        for(int x : nums)
            num_subsets *= 2;

        for(bitmap = 0; bitmap < num_subsets; bitmap++)
        {
            bits = get_bits(bitmap);
            subset = {};
            for(int x : bits)
                subset.push_back(nums[x]);
            result.push_back(subset);
        }

        return result;
    }
    // Given a integer, return all bits with value one in binary
    vector<int> get_bits(int bitmap)
    {
        vector<int> result;
        int i = 0;
        while(bitmap)
        {
           if((bitmap % 2) != 0) 
               result.push_back(i);
           bitmap = bitmap >> 1;
           i++;
        }
        return result;

    }
};

int main()
{
    vector<int> vals = {1,2,3};
    vector<vector<int>> result;
    result = Solution().subsets(vals);
    print_2dvec(result);

}


void print_2dvec(vector<vector<int>>& vec)
{
    for(vector<int> one_vec : vec)
    {
        cout << "[";
        for(int x : one_vec)
            cout << x << " ";
        cout << "] ";
    }
    cout << endl;
}

void print_vec(vector<int> nums)
{
    for(int x : nums)
        cout << x << " ";
    cout << endl;
}
