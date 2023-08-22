
#include "utils.h"

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        print_2dvec(intervals);
        cout << endl;

        int n = intervals.size();
        int pre = 0;
        int post, old_end;
        vector<vector<int>> ans;
        while(pre < n)
        {
            ans.push_back(intervals[pre]);
            old_end = intervals[pre][1];
            post = pre + 1;
            while(post < n && intervals[post][0] <= old_end)
            {
                ans.pop_back();
                ans.push_back({intervals[pre][0], max(old_end, intervals[post][1])});
                old_end = (*(ans.end() - 1))[1];
                post++;
            }
            pre = post;
        }
        return ans;
    }

};

int main()
{
    vector<vector<int>> intervals = {{1,4},{0,2},{3,5}};
    vector<vector<int>> ans = Solution().merge(intervals);
    print_2dvec(ans);

}
