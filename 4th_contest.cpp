#include <iostream>
#include <vector>
#include <stack>
#include <bits/stdc++.h>

using namespace std;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    long long k;

    cin >> n >> k;

    vector<long long> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    long long answer = 0;

    int l = 0;

    for (int r = 0; r < n; r++) {
        while (a[r] - a[l] > k) {
            l++;
        }

        long long cnt = r - l;

        answer += cnt * (cnt - 1) / 2;
    }

    cout << answer;
    

    return 0;
}
