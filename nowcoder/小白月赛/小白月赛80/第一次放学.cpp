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
    sort(all(a));
    vector<int> c(m + 1);
    for(int i = 0; i < n; i ++ ) c[a[i]] ++;
    sort(all(c));
    int maxv = 0;
    for(int i = 1; i <= m; i ++ ) {
        if(k > c[i]) k -= c[i];
        else {
            c[i] -= k;
            maxv = i;
            break;
        }
    }
    cout << c[m - 1] << endl;
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