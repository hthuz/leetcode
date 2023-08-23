
#include "utils.h"
#include <ostream>
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        if(graph.empty())
            return {};
        int n = graph.size();
        this->graph = graph;
        this->removed_node = vector<int>(n,0);
        this->graph_rm_node = vector<int>(n,0);
        vector<int> safe_nodes = {};
        vector<int> terminal_nodes;

        // Create reverse graph
        vector<vector<int>> rev_graph = vector<vector<int>>(n,vector<int>());
        for(int i = 0; i < n; i++)
            for(vector<int>::iterator dest = graph[i].begin(); dest != graph[i].end(); dest++)
                rev_graph[*dest].push_back(i);
        
        // Delete terminal node one by one
        while(!(terminal_nodes = get_terminal_node()).empty())
        {
            for(vector<int>::iterator node = terminal_nodes.begin(); node != terminal_nodes.end(); node++)
            {
                removed_node[*node] = 1;
                safe_nodes.push_back(*node);
                for(vector<int>::iterator src = rev_graph[*node].begin(); src != rev_graph[*node].end(); src++)
                    graph_rm_node[*src]++;
            }
        }
        sort(safe_nodes.begin(), safe_nodes.end());
        return safe_nodes;
    }
private:
    vector<vector<int>> graph;
    vector<int> removed_node;
    vector<int> graph_rm_node; // Indiate how many nodes are deleted for each node.
    // Return -1 if there's no terminal node
    vector<int> get_terminal_node() {
        int n = graph.size();
        vector<int> terminal_nodes = {};
        for(int i = 0; i < n; i++)
            if(graph[i].size() == graph_rm_node[i] && !removed_node[i])
                terminal_nodes.push_back(i);
        return terminal_nodes;
                
    }
    
};

int main()
{
    vector<vector<int>> graph = {};
    vector<int> ans = Solution().eventualSafeNodes(graph);
    for(int x : ans)
        cout << x << " ";
    cout << endl;

}
