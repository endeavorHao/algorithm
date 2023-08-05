#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
const int N = 3010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
int dist[N];
bool st[N];
int h[N], e[N], w[N], ne[N], idx;
int id[N];
int n, p, m;
void add(int a, int b, int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}
int dijkstra(int pos){
    memset(dist, 0x3f, sizeof dist);
    memset(st, false, sizeof st);
    priority_queue<PII, vector<PII>, greater<PII>> q;
    q.push({0, pos});
    dist[pos] = 0;
    while(q.size()){
        auto t = q.top();
        q.pop();
        if(st[t.y]) continue;
        st[t.y] = true;

        for(int i = h[t.y]; ~i; i = ne[i]){
            int j = e[i];
            if(dist[j] > t.x + w[i]){
                dist[j] = t.x + w[i];
                q.push({dist[j], j});
            }
        }
    }
    int sum = 0;
    for(int i = 1; i <= n; i ++ ){
        if(dist[id[i]] == INF) return INF;
        sum += dist[id[i]];
    }
    return sum;
}
void solve(){
	cin >> n >> p >> m;
    for(int i = 1; i <= n; i ++ ) cin >> id[i];
    memset(h, -1, sizeof h);
    while(m -- ){
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }
    int ans = INF;
    for(int i = 1; i <= p; i ++ ){
        ans = min(ans, dijkstra(i));
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