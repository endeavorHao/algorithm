#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
void solve(){
    string target = "snuke";
    int n, m;
    cin >> n >> m;
    vector<vector<char>> g(n, vector<char>(m));
    for(int i = 0; i < n; i ++ )
        for(int j = 0; j < m; j ++ ) cin >> g[i][j];
    
    auto bfs = [&]() -> bool{
        int dx[4] = {0, -1, 0, 1}, dy[4] = {1, 0, -1, 0};
        queue<PII> q;
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        q.push({0, 0});
        while(q.size()){
            auto t = q.front();
            q.pop();

            char c = g[t.x][t.y];
            int k = target.find(c);
            if(t.x == n - 1 && t.y == m - 1) return true;
            for(int i = 0; i < 4; i ++ ){
                int x = t.x + dx[i], y = t.y + dy[i];
                if(x < 0 || x >= n || y < 0 || y >= m) continue;
                if(vis[x][y]) continue;
                int ne = target.find(g[x][y]);
                if(k + 1 == ne || c == 'e' && g[x][y] == 's'){
                    vis[x][y] = true;
                    q.push({x, y});
                }
            }
        }
        return false;
    };
    if(bfs()){
        cout << "Yes" << endl;
    }else {
        cout << "No" << endl;
    }
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