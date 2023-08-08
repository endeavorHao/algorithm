#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 600, M = 1 << 10, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
int g[N][N];
int n, m, p, k;
int h[N], e[N], ne[N], w[N], idx;
int key[N];
int dist[N][M];
bool st[N][N];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
set<PII> edge;
void add(int a, int b, int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}
void build(){
    for(int i = 1; i <= n; i ++ )
        for(int j = 1; j <= m; j ++ ){
            for(int u = 0; u < 4; u ++ ){
                int x = i + dx[u], y = j + dy[u];
                if(x <= 0 || x > n || y <= 0 || y > m) continue;
                int a = g[i][j], b = g[x][y];
                if(!edge.count({a, b})) add(a, b, 0);
            }
        }
}
int bfs(){
    deque<PII> q;
    q.push_front({1, 0});
    memset(dist, 0x3f, sizeof dist);
    dist[1][0] = 0;
    while(q.size()){
        auto t = q.front();
        q.pop_front();
        if(st[t.x][t.y]) continue;
        st[t.x][t.y] = true;
        
        if(t.x == n * m) return dist[t.x][t.y];

        if(key[t.x]){
            int state = t.y | key[t.x];
            if(dist[t.x][state] > dist[t.x][t.y]){
                dist[t.x][state] = dist[t.x][t.y];
                q.push_front({t.x, state});
            }
        }
        for(int i = h[t.x]; ~i; i = ne[i]){
            int j = e[i];
            if (w[i] && !(t.y >> w[i] - 1 & 1)) continue;   // 有门并且没有钥匙
            if(dist[j][t.y] > dist[t.x][t.y] + 1){
                dist[j][t.y] = dist[t.x][t.y] + 1;
                q.push_back({j, t.y});
            }
        }
    }
    return -1;
}
void solve(){
	cin >> n >> m >> p >> k;
    memset(h, -1, sizeof h);
    int cnt = 1;
    for(int i = 1; i <= n; i ++)
        for(int j = 1; j <= m; j ++ )
            g[i][j] = cnt ++;
    while(k -- ){
        int x1, y1, x2, y2, c;
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        int a = g[x1][y1], b = g[x2][y2];
        edge.insert({a, b}), edge.insert({b, a});
        if(c) add(a, b, c), add(b, a, c);
    }
    build();

    int s;
    cin >> s;
    while(s -- ){
        int x, y, c;
        cin >> x >> y >> c;
        key[g[x][y]] |= 1 << (c - 1); 
    }
    cout << bfs() << endl;
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