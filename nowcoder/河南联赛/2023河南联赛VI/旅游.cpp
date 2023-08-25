#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
using namespace std;
const int N = 200010, INF = 0x3f3f3f3f, mod = 1000000007;
typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
int h[N], e[N], ne[N], idx;
int sum[N], cnt;
int dist[N];
bool st[N];
void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}
void dijkstra(int x){
    priority_queue<PIII, vector<PIII>, greater<PIII>> heap;
    memset(st, false, sizeof st);
    memset(dist, 0x3f, sizeof dist);
    dist[x] = 0;
    heap.push({0, {x, -1}});
    while(heap.size()){
        auto t = heap.top();
        heap.pop();

        if(st[t.y.x]) continue;
        st[t.y.x] = true;
        int s = -1;
        for(int i = h[t.y.x]; ~i; i = ne[i], s ++){
            int j = e[i];
            if(dist[j] > t.x + 1){
                dist[j] = t.x + 1;
                heap.push({dist[j], {j, t.y.x}});
            }
        }
        if(!s) sum[++cnt] = t.x;
    }
}
void solve(){
	int n;
    cin >> n;
    if(n == 1){
        printf("0.000\n");
        return;
    }
    memset(h, -1, sizeof h);
    for(int i = 0; i < n - 1; i ++ ){
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }
    dijkstra(1);
    int maxv = 1;
    for(int i = 1; i <= n; i ++ ){
        if(dist[i] > dist[maxv]){
            maxv = i;
        }
    }
    cnt = 0;
    dijkstra(maxv);
    sort(sum + 2, sum + cnt);
    int s = 0, j = 0;
    for(int i = 2; i <= cnt; i ++ ){
        if(sum[i] != sum[i - 1]) s += sum[i], j ++;
    }
    double s1 = 1.0 * s / j;
    maxv = 1;
    for(int i = 1; i <= n; i ++ ){
        if(dist[i] > dist[maxv]){
            maxv = i;
        }
    }
    cnt = 0;
    dijkstra(maxv);
    s = 0, j = 0;
    for(int i = 2; i <= cnt; i ++ ){
        if(sum[i] != sum[i - 1]) s += sum[i], j ++;
    }
    double s2 = 1.0 * s / j;
    printf("%.3lf\n", max(s1, s2));
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