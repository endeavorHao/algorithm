#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 1000010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;
void solve(){
	int m, n;
    cin >> m >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i ++ ) cin >> a[i];
    vector<int> s(1010);
    vector<bool> vis(1010);
    int ans = 0;
    for(int i = 0; i < n; i ++ ){
        if(vis[a[i]]) continue;
        s[ ++ ans ] = a[i];
        vis[a[i]] = true;
        if(ans > m) vis[s[ans - m]] = false;
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