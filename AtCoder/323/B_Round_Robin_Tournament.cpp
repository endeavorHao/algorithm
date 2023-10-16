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
    vector<vector<char>> g(n, vector<char>(n));
    for(int i = 0; i < n; i ++ ) {
        for(int j = 0; j < n; j ++ ) cin >> g[i][j];
    }
    vector<PII> ans(n);
    for(int i = 0; i < n; i ++ ) {
        int cnt = 0;
        for(int j = 0; j < n; j ++ ) {
            if(g[i][j] == 'o') cnt ++;
        }
        ans[i] = {cnt, i + 1};
    }
    sort(all(ans), [](PII a, PII b){
        if(a.x == b.x) return a.y < b.y;
        return a.x > b.x;
    });
    for(int i = 0; i < n; i ++ ) cout << ans[i].y << " \n"[i == n - 1];
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