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
    vector<vector<int>> g(n, vector<int>(m));
    for(int i = 0; i < n; i ++ )
        for(int j = 0; j < m; j ++ ) cin >> g[i][j];
    int ans = 0;
    for(int i = 0; i < n; i ++ ){
        for(int j = 0; j < m; j ++ ){
            int sum = 0;
            for(int x = i - 1, y = j - 1; x >= 0 && y >= 0; x --, y -- ) sum += g[x][y];
            for(int x = i + 1, y = j + 1; x < n && y < m; x ++, y ++ ) sum += g[x][y];
            for(int x = i - 1, y = j + 1; x >= 0 && y < m; x --, y ++ ) sum += g[x][y];
            for(int x = i + 1, y = j - 1; x < n && y >= 0; x ++, y -- ) sum += g[x][y];
            ans = max(ans, sum + g[i][j]);
        }
    }
    cout << ans << endl;
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int T = 1;
	cin >> T;
	while(T -- ){
		solve();
	}
	return 0;
}