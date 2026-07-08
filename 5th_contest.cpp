#include <iostream>
#include <utility>

using namespace std;

const long long MOD = 1000000007;

pair<long long, long long> powerAndSum(long long q, long long n) {
    if (n == 0) {
        return {1, 0};
    }

    auto half = powerAndSum(q, n / 2);

    long long p = half.first;
    long long s = half.second;

    long long p2 = p * p % MOD;

    long long s2 = s * (1 + p) % MOD;

    if (n % 2 == 0) {
        return {p2, s2};
    } else {
        long long pn = p2 * q % MOD;
        long long sn = (s2 + p2) % MOD;

        return {pn, sn};
    }
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--) {
        long long b1, q, n;
        cin >> b1 >> q >> n;

        b1 %= MOD;
        q %= MOD;

        auto result = powerAndSum(q, n);

        long long sumQ = result.second;

        long long answer = b1 * sumQ % MOD;

        cout << answer << '\n';
    }

    return 0;
}
