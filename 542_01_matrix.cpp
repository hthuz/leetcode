
#include "utils.h"


#define INF 30000

// O(mn(m + n))
class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        return bfs_sol(mat);
    }
private:
    vector<vector<int>> naive_sol(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> dis(m,vector<int>(n,0));
        // Initialization
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(mat[i][j])
                    dis[i][j] = INF;
        // iterate for m + n times
        for(int k = 0; k < m + n; k++) {
            for(int i = 0; i < m; i++) {
                for(int j = 0; j < n; j++) {
                    // Update
                    if(i < m - 1)
                        dis[i][j] = min(dis[i][j], 1 + dis[i + 1][j]);
                    if(i)
                        dis[i][j] = min(dis[i][j], 1 + dis[i - 1][j]);
                    if(j < n - 1)
                        dis[i][j] = min(dis[i][j], 1 + dis[i][j + 1]);
                    if(j)
                        dis[i][j] = min(dis[i][j], 1 + dis[i][j - 1]);
                }
            }
        }
        return dis;
    }
    vector<vector<int>> bfs_sol(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        vector<vector<int>> dis(m,vector<int>(n,0));
        queue<pair<int,int>> to_explore;
        // Initialization
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(!mat[i][j]) {
                    to_explore.push({i,j}); 
                    visited[i][j] = 1;
                }
        // BFS
        while(!to_explore.empty())
        {
            pair<int,int> node = to_explore.front();
            to_explore.pop();
            vector<pair<int,int>> adj_nodes = {};
            if(node.first < m - 1)
                adj_nodes.push_back({node.first + 1, node.second});
            if(node.first)
                adj_nodes.push_back({node.first - 1, node.second});
            if(node.second < n - 1)
                adj_nodes.push_back({node.first, node.second + 1});
            if(node.second)
                adj_nodes.push_back({node.first, node.second - 1});

            for(pair<int,int> adj_node : adj_nodes) {
                if(!visited[adj_node.first][adj_node.second]) {
                    dis[adj_node.first][adj_node.second] = dis[node.first][node.second] + 1;
                    visited[adj_node.first][adj_node.second] = 1;
                    to_explore.push(adj_node);
                }
            }
        }

        return dis;
    }
};

int main()
{
    vector<vector<int>> mat(3,vector<int>(3,0));
    mat[1][1] = 1;
    mat[2][0] = 1;
    mat[2][1] = 1;
    mat[2][2] = 1;
    // vector<vector<int>> mat(5, vector<int>(1,0));
    vector<vector<int>> ans;
    ans = Solution().updateMatrix(mat);
    print_2dvec(ans);

}


