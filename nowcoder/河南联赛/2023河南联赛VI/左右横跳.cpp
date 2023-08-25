#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
void solve(){
	int n, m, k;
    cin >> n >> m >> k;
    vector<vector<int>> a(n, vector<int>(m));
    for(int i = 0; i < n; i ++ ){
        for(int j = 0; j < m; j ++ ) cin >> a[i][j];
    }
    vector<vector<int>> score(n, vector<int>(m));
    vector<vector<bool>> vis(n, vector<bool>(m));
    queue<PII> q;
    for(int i = 0; i < m; i ++ ){
        q.push({0, i});
        score[0][i] = a[0][i];
    }
    while(q.size()){
        auto t = q.front();
        q.pop();
        // cout << t.x << ' ' << t.y << ' ' << score[t.x][t.y] << endl;
        if(vis[t.x][t.y]) continue;
        vis[t.x][t.y] = true;
        if(t.x + 1 < n){
            q.push({t.x + 1, t.y});
            score[t.x + 1][t.y] = score[t.x][t.y];
        }
        for(int j = 0; j < m; j ++ ){
            if(t.x + k >= n) continue;
            if(score[t.x + k][j] < score[t.x][t.y] + a[t.x + k][j]){
                score[t.x + k][j] = score[t.x][t.y] + a[t.x + k][j];
                q.push({t.x + k, j});
            }
        }
    }
    int ans = 0;
    for(int i = 0; i < m; i ++ ){
        ans = max(ans, score[n - 1][i]);
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