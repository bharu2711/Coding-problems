class Solution {
public:
    int minimumEdgeReversal(vector<vector<int>>& edges, int n, int src, int dst) {
        // Create an adjacency list to represent the graph
        vector<vector<pair<int, int>>> adj(n + 1, vector<pair<int, int>>());

        // Populate the adjacency list with edges, considering each edge as two directed edges
        for (vector<int>& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].emplace_back(v, 0);  // Original edge
            adj[v].emplace_back(u, 1);  // Reverse edge
        }

        // Create a priority queue for Dijkstra's algorithm
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        // Initialize vectors for visited nodes and minimum distances
        vector<bool> visited(n + 1, false);
        vector<int> ans(n + 1, INT_MAX);
        ans[src] = 0;

        // Push the source node into the priority queue
        pq.push({0, src});

        // Dijkstra's algorithm
        while (!pq.empty()) {
            pair<int, int> p = pq.top();
            pq.pop();

            int dist = p.first;
            int node = p.second;

            // Skip if the node is already visited
            if (visited[node]) continue;

            // Mark the node as visited
            visited[node] = true;

            // Explore neighbors and update distances
            for (pair<int, int>& p2 : adj[node]) {
                int nbrNode = p2.first;
                int nbrWt = p2.second;

                // Relaxation step: Update distance if a shorter path is found
                if (ans[node] + nbrWt < ans[nbrNode]) {
                    ans[nbrNode] = ans[node] + nbrWt;
                    pq.push({ans[nbrNode], nbrNode});
                }
            }
        }

        // If destination node is unreachable, return -1; otherwise, return the minimum distance to it
        return (ans[dst] == INT_MAX) ? -1 : ans[dst];
    }
};


