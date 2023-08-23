


//
// Version 1.0 My solution is to remove terminal nodes every time and update graph until there's no terminal nodes
// The time complexity can be high
// The problem is actually equivalent to find all nodes not in any cycle.
// Version 2.0 Use queue to speed up.
//
#include "utils.h"
#include <ostream>
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> safe_nodes = {};
        vector<int> out_deg = vector<int>(n,0);
        queue<int> q;

        // Create reverse graph
        vector<vector<int>> rev_graph = vector<vector<int>>(n,vector<int>());
        for(int i = 0; i < n; i++) {
            for(int dest : graph[i])
                rev_graph[dest].push_back(i);
            out_deg[i] = graph[i].size();
            if(!out_deg[i])
                q.push(i);
        }

        while(!q.empty())
        {
            int node = q.front();
            // safe_nodes.push_back(node);
            q.pop();
            for(int src : rev_graph[node])
                if (--out_deg[src] == 0)
                    q.push(src);
        }

        for(int i = 0; i < n; i++)
            if(!out_deg[i])
                safe_nodes.push_back(i);
        // sort(safe_nodes.begin(), safe_nodes.end());
        return safe_nodes;
    }
    
};

int main()
{
    vector<vector<int>> graph = {{1,2},{2,3},{5},{0},{5},{},{}};
    vector<int> ans = Solution().eventualSafeNodes(graph);
    for(int x : ans)
        cout << x << " ";
    cout << endl;

}
