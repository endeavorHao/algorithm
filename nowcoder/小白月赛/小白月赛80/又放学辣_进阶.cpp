#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i ++ ) cin >> a[i];
    vector<int> c(m + 1);
    for(int i = 0; i < n; i ++ ) {
        c[a[i]] ++;
    }
    auto check = [&](int pos, int mid) ->bool{
        int cnt = 0;
        for(int i = 1; i <= m; i ++ ) {
            if(i == pos) continue;
            if(c[i] >= mid) cnt += c[i] - mid; 
        }
        return cnt <= k;
    };
    for(int i = 1; i <= m; i ++ ) {
        int l = 0, r = 1e6;
        while(l < r) {
            int mid = l + r >> 1;
            if(check(i, mid)) r = mid;
            else l = mid + 1;
        }
        if(n - k < c[i]) cout << -1 << " ";
        else cout << r << " ";
    }
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while(T -- ){
        solve();
    }
    return 0;
}