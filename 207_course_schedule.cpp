
#include "utils.h"


class Solution {
private:
    vector<vector<int>> edges;
    vector<int> visited;
    vector<int> rec_stack;
    bool dfs(int vertex) {

        rec_stack[vertex] = 1;

        int ans = true;
        for(int adj_vertex : edges[vertex])
        {
            if(rec_stack[adj_vertex])
                ans = false;
            if(!visited[adj_vertex]) {
                visited[adj_vertex] = 1;
                ans = ans && dfs(adj_vertex);
            }
        }
        rec_stack[vertex] = 0;

        return ans;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        this->edges = vector<vector<int>>(numCourses, vector<int>());
        for(vector<vector<int>>::iterator prereq = prerequisites.begin(); prereq != prerequisites.end(); prereq++)
            edges[(*prereq)[0]].push_back((*prereq)[1]);
        this->visited = vector<int>(numCourses, 0);
        this->rec_stack = vector<int>(numCourses, 0);

        bool ans = true;
        for(int vertex = 0; vertex < numCourses; vertex++)
        {
            if(!visited[vertex]) {
                visited[vertex] = 1;
                ans = ans && dfs(vertex);
            }
        }
        return ans;
    }
};

int main()
{
    int numCourses = 4;
    vector<vector<int>> prerequisites = {{0,1},{1,2},{2,3},{0,2},{1,3},{3,0}};
    bool ans = Solution().canFinish(numCourses, prerequisites);
    cout << ans << endl;

}
