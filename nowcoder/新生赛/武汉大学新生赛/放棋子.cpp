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
	int n, m;
    cin >> n >> m;
    vector<vector<char>> g(n, vector<char>(m));
    for(int i = 0; i < n; i ++ ) {
        for(int j = 0; j < m; j ++ ) {
            cin >> g[i][j];
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i ++ ){
        int cnt = 0;
        for(int j = 0; j < m; j ++ ){
            if(g[i][j] == '#') cnt ++;
            else cnt = 0;
            ans += cnt * cnt;
        }
    }
    for(int i = 0; i < m; i ++ ){
        int cnt = 0;
        for(int j = 0; j < n; j ++ ){
            if(g[j][i] == '#') cnt ++;
            else cnt = 0;
            ans += cnt * cnt;
        }
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