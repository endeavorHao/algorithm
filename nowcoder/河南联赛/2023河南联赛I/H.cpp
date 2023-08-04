#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 4010, INF = 0x3f3f3f3f;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
int n, m;
int a[N];
char g[N][N];
int c[N][N];
int dist[N][N];
int dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
int bfs(){
    priority_queue<PIII, vector<PIII>, greater<PIII>> q;
    q.push({0, {1, 1}});
    memset(dist, 0x3f, sizeof dist);
    dist[1][1] = 0;
    while(q.size()){
        auto t = q.top();
        q.pop();
        if(t.y.x == n && t.y.y == m) return t.x;
        if(g[t.y.x][t.y.y] == '*'){
            int k = c[t.y.x][t.y.y];
            for(int i = 0; i < 4; i ++ ){
                int x = t.y.x + k * dx[i], y = t.y.y + k * dy[i];
                if(x <= 0 || x > n || y <= 0 || y > m) continue;
                if(g[x][y] == '#') continue;
                if(dist[x][y] > t.x){
                    dist[x][y] = t.x;
                    q.push({t.x, {x, y}});
                }
            }
        }else{
            for(int i = 0; i < 4; i ++ ){
                int x = t.y.x + dx[i], y = t.y.y + dy[i];
                if(x <= 0 || x > n || y <= 0 || y > m) continue;
                if(g[x][y] == '#') continue;
                if(dist[x][y] > t.x + 1){
                    dist[x][y] = t.x + 1;
                    q.push({dist[x][y], {x, y}});
                }
            }
        }
    }
    return -1;
}
void solve(){
    cin >> n >> m;
    for(int i = 1; i <= n; i ++ ) cin >> g[i] + 1;
    int k;
    cin >> k;
    while(k -- ){
        int x, y, d;
        cin >> x >> y >> d;
        c[x][y] = d;
    }
    cout << bfs() << endl;
}
signed main() {
    #ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
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