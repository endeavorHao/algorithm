#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
int h[N], e[N], w[N], ne[N], idx;
int n, ans;
void add(int a, int b, int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}
int dfs(int u, int fa){
    int d1 = 0, d2 = 0;
    for(int i = h[u]; ~i; i = ne[i]){
        int j = e[i];
        if(j == fa) continue;
        int d = dfs(j, u) + w[i];
        if(d >= d1) d2 = d1, d1 = d;
        else if(d > d2) d2 = d;
    }
    ans = max(ans, d1 + d2);
    return d1;
}
void solve(){
	cin >> n;
    memset(h, -1, sizeof h);
    for(int i = 0; i < n - 1; i ++ ){
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }
    dfs(1, -1);
    cout << ans << endl;
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