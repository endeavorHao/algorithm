#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ff first
#define ss second
#define endl '\n'
#define PII pair<int, int>
#define PIII pair<int, PII>

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n, m, k, l, r;
    cin >> n >> m >> k;
    vector<int> diff(n + 2);
    while (m--) {
        cin >> l >> r;
        diff[l]++;
        diff[r]--;
    }
    int ans = 0, cnt = 0;
    for (int i = 0; i < n + 2; ++i) {
        cnt += diff[i];
        ans = max(ans, (cnt + k - 1) / k);
    }
    cout << ans << endl;
}