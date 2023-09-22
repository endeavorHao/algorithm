#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define endl "\n"
#define all(v) v.begin(), v.end()
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
void solve(){
	int n;
    cin >> n;
    vector<vector<int>> g(n, vector<int>(n));
    for(int i = 0; i < n; i ++ ) {
        for(int j = 0; j < n; j ++ ) cin >> g[i][j];
    }
    vector<int> ans;
    for(int i = 0; i < n; i ++ ){
        bool ok = true;
        for(int j = 0; j < n; j ++ ){
            if(g[i][j] == 1 || g[i][j] == 3) ok = false;
        }
        if(ok) ans.push_back(i);
    }
    cout << ans.size() << endl;
    for(auto u: ans) cout << u + 1 << " ";
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