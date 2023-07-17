// 思路是以每个传送门为起点跑40边dijkstra
// 因为图点虽然很多，但边不多

#include <bits/stdc++.h>
#define x first
#define y second 
#define int long long 
using namespace std;
const int N = 53000, INF = 0x3f3f3f3f; 
typedef pair<int, int> PII;
int n, m;
int dist[40][N];
int a[N], s[N];
int h[N], e[N * 2], ne[N * 2], w[N * 2], idx;
int p[N], cnt;
bool st[40][N];
void add(int a, int b, int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}
void dijkstra(int s, int T){
    dist[T][s] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> q;
    q.push({0, s});
    while(q.size()){
        auto t = q.top();
        q.pop();
        if(st[T][t.y]) continue;
        st[T][t.y] = true;
//         cout << t.x << ' ' << t.y  <<' ' << dist[T][t.y] << endl;
        for(int i = h[t.y]; ~i; i = ne[i]){
            int j = e[i];
            if(dist[T][j] > t.x + w[i]){
                dist[T][j] = t.x + w[i];
                q.push({dist[T][j], j});
            }
        }
    }
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    cin >> n >> m;
    memset(h, -1, sizeof h);
    for(int i = 1; i <= n; i ++ ){
        int c;
        cin >> c;
        if(i < n) add(i, i + 1, c), add(i + 1, i, c);
        else add(n, 1, c), add(1, n, c);
        a[i] = c;
    }
    for(int i = 1; i <= n; i ++ ) s[i] = s[i - 1] + a[i];
    while(m -- ){
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
        p[cnt ++ ] = a, p[cnt ++ ] = b;
    }
    sort(p, p + cnt);
    memset(dist, 0x3f, sizeof dist);
    for(int i = 0; i < cnt; i ++ ){
        dijkstra(p[i], i);
    }
    int q;
    cin >> q;
    while(q -- ){
        int S, T;
        cin >> S >> T;
        int ans = INF;
        if(T > S) swap(T, S);
        ans = abs(s[S - 1] - s[T - 1]); 
//         cout << ans << ' ';
        ans = min(s[n] - ans, ans);
//         cout << ans << ' ';
        for(int i = 0; i < cnt; i ++ ){
            ans = min(ans, dist[i][T] + dist[i][S]);
        }
        cout << ans << endl;
    }
	return 0;
} 