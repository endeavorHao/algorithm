#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 500010, INF = 0x3f3f3f3f, mod = 1000000007;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;

int p[N];
int find(int x) {
    if(x != p[x]) p[x] = find(p[x]);
    return p[x];
}

void solve(){
	int n, m;
    cin >> n >> m;
    vector<array<int, 2>> adj(m);
    for(int i = 1; i <= n; i ++ ) p[i] = i;
    for(int i = 0; i < m; i ++ ) {
        int a, b;
        cin >> a >> b;
        adj[i] = {a, b};
    }
    int ans = 0;
    for(auto [u, v]: adj) {
        u = find(u), v = find(v);
        if(u == v) {
            ans ++;
        }else p[u] = v;
    }
    cout << ans << endl;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T = 1;
    cout << fixed << setprecision(16);
	// cin >> T;
	while(T -- ){
		solve();
	}
	return 0;
}