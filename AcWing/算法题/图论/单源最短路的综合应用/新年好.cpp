#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
const int N = 50010, M = 200010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
int n, m;
int dist[6][N];
bool st[N];
int id[6];
int h[N], e[M], w[M], ne[M], idx;
void add(int a, int b, int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}
void dijkstra(int s, int dist[]){
    memset(st, false, sizeof st);
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, s});
    dist[s] = 0;
    while(heap.size()){
        auto t = heap.top();
        heap.pop();

        if(st[t.y]) continue;
        st[t.y] = true;
        for(int i = h[t.y]; ~i; i = ne[i]){
            int j = e[i];
            if(dist[j] > t.x + w[i]){
                dist[j] = t.x + w[i];
                heap.push({dist[j], j});
            }
        }
    }
}
int dfs(int u, int start, int sum){
    if(u == 6){
        return sum;
    }
    int res = INF;
    for(int i = 1; i < 6; i ++ ){
        if(!st[i]){
            st[i] = true;
            res = min(res, dfs(u + 1, i, sum + dist[start][id[i]]));
            st[i] = false;
        }
    }
    return res;
}
void solve(){
    cin >> n >> m;
    id[0] = 1;
    for(int i = 1; i < 6; i ++ ) cin >> id[i];
    memset(h, -1, sizeof h);
    while(m -- ){
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }
    memset(dist, 0x3f, sizeof dist);
    for(int i = 0; i < 6; i ++ ) dijkstra(id[i], dist[i]);

    memset(st, 0, sizeof st);
    cout << dfs(1, 0, 0) << endl;
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