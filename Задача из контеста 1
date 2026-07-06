#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int T;
    cin >> T;
    
    while (T--) {
        int N;
        cin >> N;
        
        vector<int> a(N);
        
        for (int i=0; i<N; i++) {
            cin >> a[i];
        }
        
        long long answer = 0;
        
        for (int i=0; i<N; i++) {
            for (int j=i+1; j<N; j++) {
                if (a[i] > a[j]) {
                    answer++;
                }
            }
        }
        cout << answer << "\n";
    }
    
    return 0;
}
