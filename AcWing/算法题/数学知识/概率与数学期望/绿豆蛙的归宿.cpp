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

int h[N], e[N], ne[N], w[N], idx;
int dout[N];
double f[N];
void add(int a, int b, int c) {
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}

int n, m;
double dp(int u) {
    auto &v = f[u];
    if(v >= 0) return v;
    v = 0;
    for(int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        v += (dp(j) + w[i]) / dout[u];
    }
    return v;
}

void solve(){
    cin >> n >> m;
    memset(h, -1, sizeof h);
    for(int i = 0; i < m; i ++ ) {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
        dout[a] ++;
    }
    memset(f, -1, sizeof f);
    cout << dp(1) << endl;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    cout << fixed << setprecision(2);
	int T = 1;
	// cin >> T;
	while(T -- ){
		solve();
	}
	return 0;
}