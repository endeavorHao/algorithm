#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
int h[N], e[N], ne[N], w[N], idx;
int n, m, k;
int dist[N];
bool st[N];
void add(int a, int b, int c){
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx ++; 
}
bool check(int mid){
    memset(dist, 0x3f, sizeof dist);
    memset(st, false, sizeof st);
    dist[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, 1});
    while(heap.size()){
        auto t = heap.top();
        heap.pop();

        if(st[t.y]) continue;
        st[t.y] = true;
        for(int i = h[t.y]; ~i; i = ne[i]){
            int j = e[i];
            int d = w[i] > mid;
            if(dist[j] > t.x + d){
                dist[j] = t.x + d;
                heap.push({dist[j], j});
            }
        }
    }
    return dist[n] <= k;
}
void solve(){
	cin >> n >> m >> k;
    memset(h, -1, sizeof h);
    while(m -- ){
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }
    int l = 0, r = 1e9 + 1;
    while(l < r) {
        int mid = l + r >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    if(r == 1e9 + 1) cout << -1 << endl;
    else 
        cout << r << endl;
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