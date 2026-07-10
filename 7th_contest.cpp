#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int, long long>>> graph(n + 1);

    for (int i = 0; i < m; i++) {
        int u, v;
        long long w;

        cin >> u >> v >> w;

        graph[u].push_back({v, w});
    }

    const long long INF = 4e18;

    vector<long long> dist(n + 1, INF);
    vector<int> parent(n + 1, -1);

    priority_queue<
        pair<long long, int>,
        vector<pair<long long, int>>,
        greater<pair<long long, int>>
    > pq;

    dist[1] = 0;
    pq.push({0, 1});

    while (!pq.empty()) {
        long long currentDist = pq.top().first;
        int v = pq.top().second;
        pq.pop();

        if (currentDist != dist[v]) {
            continue;
        }

        for (auto edge : graph[v]) {
            int to = edge.first;
            long long weight = edge.second;

            if (dist[v] + weight < dist[to]) {
                dist[to] = dist[v] + weight;
                parent[to] = v;
                pq.push({dist[to], to});
            }
        }
    }

    if (dist[n] == INF) {
        cout << -1;
        return 0;
    }

    vector<int> path;

    int current = n;

    while (current != -1) {
        path.push_back(current);
        current = parent[current];
    }

    reverse(path.begin(), path.end());

    for (int vertex : path) {
        cout << vertex << ' ';
    }

    return 0;
}
