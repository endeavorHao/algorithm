#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
void solve(){
    int n, m;
    cin >> n >> m;
    vector<string> c(n), d(m);
    map<string, int> cut;
    for(int i = 0; i < n; i ++ ) cin >> c[i];
    for(int i = 0; i < m; i ++ ) cin >> d[i];
    int p0 = 0;
    cin >> p0;
    for(int i = 0; i < m; i ++ ){
        int x;
        cin >> x;
        cut[d[i]] = x;
    }
    int ans = 0;
    for(int i = 0; i < n; i ++ ){
        if(!cut[c[i]]) ans += p0;
        else ans += cut[c[i]];
    }
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