    #include <bits/stdc++.h>
    #define x first
    #define y second
    #define int long long
    #define endl "\n"
    #define all(v) v.begin(), v.end()
    using namespace std;
    const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;

    typedef long long LL;
    typedef unsigned long long ULL;
    typedef pair<int, int> PII;
    typedef pair<PII, int> PIII;

    int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

    void solve(){
        int n, m;
        cin >> n >> m;
        vector<string> g(n);
        for(int i = 0; i < n; i ++ ) cin >> g[i];
        vector<vector<bool>> vis(n, vector<bool>(m));
        int ans = 0;
        auto bfs = [&](int x, int y){
            queue<PII> q;
            q.push({x, y});
            vis[x][y] = true;
            while(q.size()) {
                auto t = q.front();
                q.pop();
                // vis[t.x][t.y] = true;
                for(int i = 0; i < 8; i ++ ) {
                    int x = t.x + dx[i], y = t.y + dy[i];
                    if(x < 0 || x >= n || y < 0 || y >= m) continue;
                    if(vis[x][y]) continue;
                    if(g[x][y] != '#') continue;
                    vis[x][y] = true;
                    q.push({x, y});
                }
            }
        };
        for(int i = 0; i < n; i ++ ) {
            for(int j = 0; j < m; j ++ ) {
                if(g[i][j] == '#' && !vis[i][j]) {
                    bfs(i, j);
                    ans ++;
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
        // cin >> T;
        while(T -- ){
            solve();
        }
        return 0;
    }