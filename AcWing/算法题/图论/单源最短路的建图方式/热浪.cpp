#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
int h[N], ne[N], w[N], e[N], idx;
int dist[N];
int n, m, S, T;
void add(int a, int b, int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}
int dijkstra(){
    priority_queue<PII, vector<PII>, greater<PII>> q;
    q.push({0, S});
    memset(dist, 0x3f, sizeof dist);
    dist[S] = 0;
    while(q.size()){
        auto t = q.top();
        q.pop();
        if(t.y == T) return t.x;
        for(int i = h[t.y]; ~i; i = ne[i]){
            int j = e[i];
            if(dist[j] > t.x + w[i]){
                dist[j] = t.x + w[i];
                q.push({dist[j], j});
            }
        }
    }
    return -1;
}
void solve(){
    cin >> n >> m >> S >> T;
    memset(h, -1, sizeof h);
    while(m -- ){
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }
    int t = dijkstra();
    cout << t << endl;
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