#include <iostream>
#include <vector>
#include <set>

using namespace std;

void dfs(int node, int parent, const vector<vector<int>>& adj, vector<int>& subtree_size) {
    subtree_size[node] = 1;
    for (int neighbor : adj[node]) {
        if (neighbor != parent) {
            dfs(neighbor, node, adj, subtree_size);
            subtree_size[node] += subtree_size[neighbor];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<vector<int>> adj(n + 1);
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> subtree_size(n + 1, 0);
        dfs(1, 0, adj, subtree_size);

        int max_components = 1;
        for (int i = 2; i <= n; ++i) {
            int parent = adj[i][0] == 1 ? adj[i][1] : adj[i][0];
            int component_size = subtree_size[i];
            int remaining_tree_size = n - component_size;

            if (parent != 1) {
                int parent_component_size = subtree_size[parent] - component_size;
                remaining_tree_size += parent_component_size;
            }

            max_components = max(max_components, max(component_size, remaining_tree_size));
        }

        cout << max_components << '\n';
    }

    return 0;
}