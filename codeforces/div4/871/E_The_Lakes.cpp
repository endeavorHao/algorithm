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
    int dx[] = {0, -1, 0, 1}, dy[] = {1, 0, -1, 0};
    vector<vector<bool>> vis(n, vector<bool>(m));
    auto bfs = [&](int x, int y)->int{
        int ans = 0;
        queue<PII> q;
        q.push({x, y});
        vis[x][y] = true;
        while(q.size()){
            auto [x, y] = q.front();
            q.pop();
            ans += g[x][y];
            for(int i = 0; i < 4; i ++ ){
                int a = x + dx[i], b = y + dy[i];
                if(a < 0 || a >= n || b < 0 || b >= m) continue;
                if(vis[a][b]) continue;
                if(!g[a][b]) continue;
                vis[a][b] = true;
                q.push({a, b});
            }
        }
        return ans;
    };
    int ans = 0;
    for(int i = 0; i < n; i ++ ){
        for(int j = 0; j < m; j ++ ){
            if(!vis[i][j] && g[i][j]){
                ans = max(ans, bfs(i, j));
            }
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