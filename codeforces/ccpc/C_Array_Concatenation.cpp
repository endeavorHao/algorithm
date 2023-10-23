#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 3e5 + 10, mod = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i ++ ) cin >> a[i];
    int ans = 0;
    // 只要有2
    int sum = 0;
    sum = accumulate(a.begin(), a.end(), 0ll);
    int x = n;
    for(int i = 1; i <= m - 1; i ++ ) {
        sum = sum * 2 % mod;
        x = x * 2 % mod;
    }
    ans = (2 * x + 1) * sum % mod;
    // 全1
    int t = 0;
    for(int i = 1; i <= n; i ++ ) {
        t = (t + a[i] * (n - i + 1)) % mod;
    }
    sum = accumulate(a.begin(), a.end(), 0ll);
    for(int i = 1; i <= m; i ++ ) {
        t = ( n * sum % mod + 2 * t) % mod;
        sum = sum * 2 % mod;
        n = n * 2 % mod;  
    }
    ans = max(ans, t);
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T -- ) {
        solve();
    }

    return 0;
}