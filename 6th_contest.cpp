#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    vector<string> field(n);

    for (int i = 0; i < n; i++) {
        cin >> field[i];
    }

    int x, y;
    cin >> x >> y;

    x--;
    y--;

    vector<vector<int>> dist(n, vector<int>(m, -1));

    queue<pair<int, int>> q;

    dist[x][y] = 0;
    q.push({x, y});

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    while (!q.empty()) {
        pair<int, int> current = q.front();
        q.pop();

        int i = current.first;
        int j = current.second;

        for (int dir = 0; dir < 4; dir++) {
            int ni = i + dx[dir];
            int nj = j + dy[dir];

            if (ni < 0 || ni >= n || nj < 0 || nj >= m) {
                continue;
            }

            if (field[ni][nj] == '#') {
                continue;
            }

            if (dist[ni][nj] != -1) {
                continue;
            }

            dist[ni][nj] = dist[i][j] + 1;
            q.push({ni, nj});
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << dist[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
