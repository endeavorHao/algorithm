#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
int h[N], e[N], w[N], ne[N], idx;
int dist[N];
bool st[N];
int n, m, T;
void add(int a, int b, int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++;
}
int dijkstra(){
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, 0});
    memset(dist, 0x3f, sizeof dist);
    memset(st, false, sizeof st);
    dist[0] = 0;
    while(heap.size()){
        auto t = heap.top();
        heap.pop();
        if(st[t.y]) continue;
        st[t.y] = true;
        if(t.y == T) return t.x;
        for(int i = h[t.y]; ~i; i = ne[i]){
            int j = e[i];
            if(dist[j] > t.x + w[i]){
                dist[j] = t.x + w[i];
                heap.push({dist[j], j});
            }
        }
    }
    return -1;
}
void solve(){
	while(cin >> n >> m >> T){
        memset(h, -1, sizeof h);
        idx = 0;
        while(m -- ){
            int a, b, c;
            cin >> a >> b >> c;
            add(a, b, c);
        }
        int k;
        cin >> k;
        while(k -- ){
            int x;
            cin >> x;
            add(0, x, 0);
        }
        cout << dijkstra() << endl;
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