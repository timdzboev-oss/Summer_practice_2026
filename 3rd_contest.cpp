#include <iostream>
#include <vector>

using namespace std;

const long long MOD = 1000000007;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<bool>> danger(n + 1, vector<bool>(m + 1, false));

    for (int i = 0; i < k; i++) {
        int x, y;
        cin >> x >> y;
        danger[x][y] = true;
    }

    vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));

    dp[0][0] = 1;

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (danger[i][j]) {
                dp[i][j] = 0;
                continue;
            }

            if (i == 0 && j == 0) {
                continue;
            }

            if (i > 0) {
                dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
            }

            if (j > 0) {
                dp[i][j] = (dp[i][j] + dp[i][j - 1]) % MOD;
            }
        }
    }

    cout << dp[n][m];

    return 0;
}
