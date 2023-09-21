#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
int a[N];
int f[N][17];
int n, m;
void init(){
    for(int i = 1; i <= n; i ++ ) f[i][0] = a[i];
    int p = log2(n);
    for(int k = 1; k <= p; k ++ ){
        for(int i = 1; i + (1 << k) - 1 <= n; i ++ ){
            f[i][k] = min(f[i][k - 1], f[i + (1 << (k - 1))][k - 1]);
        }
    }
}
int query(int l, int r){
    int len = r - l + 1;
    int p = log2(len);
    return min(f[l][p], f[r - (1 << p) + 1][p]);
}
void solve(){
    cin >> n >> m;
    for(int i = 1; i <= n; i ++ ) cin >> a[i];
    init();
    while(m -- ){
        int l, r;
        cin >> l >> r;
        cout << query(l, r) << ' ';
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