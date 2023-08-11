
#include "utils.h"
#include <ostream>

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        this->n = isConnected.size();
        this->visited = vector<int>(n,0);
        this->isConnected = isConnected;

        int cc_num = 1;
        dfs(0);

        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                dfs(i);
                cc_num++;
            }
        }
        return cc_num;
    }
private:
    vector<int> visited;
    vector<vector<int>> isConnected;
    int n;

    void dfs(int vertex) {
        if(visited[vertex])
            return;
        visited[vertex] = 1;
        // For all edges connected to vertex
        for(int i = 0; i < n; i++) {
            if(isConnected[vertex][i] && !visited[i]) {
                dfs(i);
            }
        }

    }
};

int main()
{
    vector<vector<int>> isConnected(4, vector<int>(4,0));
    isConnected[0][0] = 1;
    isConnected[1][1] = 1;
    isConnected[2][2] = 1;
    isConnected[3][3] = 1;

    isConnected[0][3] = 1;
    isConnected[3][0] = 1;

    isConnected[1][2] = 1;
    isConnected[2][1] = 1;

    isConnected[2][3] = 1;
    isConnected[3][2] = 1;

    int res = Solution().findCircleNum(isConnected);
    cout << res << endl;

}
